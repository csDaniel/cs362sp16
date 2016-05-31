import java.util.Random;
import junit.framework.TestCase;


public class UrlValidatorTest extends TestCase {

    private boolean status = false;

    public UrlValidatorTest(String testName) {
        super(testName);
    }



    public void testManual(){
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        // SUCCESS TESTS -------------------------------
        // Standard URLs
        System.out.println("\n http://www.hotmail.com \nResult: " +  validTester.isValid("http://www.hotmail.com"));
        System.out.println("\n http://www.facebook.com \nResult: " +  validTester.isValid("http://www.facebook.com"));

        // Https
        System.out.println("\n https://www.bing.com \nResult: " +  validTester.isValid("https://www.bing.com"));

        // Https subtld
        System.out.println("\n https://www.bing.com/maps/ \nResult: " +  validTester.isValid("https://www.bing.com/maps/"));

        // Http port
        System.out.println("\n http://www.bing.com:8000 \nResult: " +  validTester.isValid("http://www.bing.com:8000"));

        // FAILURE TESTS --------------------------------
        // Missing 'p' in http
        System.out.println("\n htt://www.facebook.com \nResult: " +  validTester.isValid("htt://www.facebook.com"));
        System.out.println("\n https://www.bing.com/ maps \nResult: " +  validTester.isValid("https://www.bing.com/ maps"));
        // Port
        System.out.println("\n http://www.bing.com:111111111111 \nResult: " +  validTester.isValid("http://www.bing.com:111111111111"));
        System.out.println("\n http://www.amazon.123 \nResult: " +  validTester.isValid("http://www.amazon.123"));
        // Empty test
        System.out.println("\n Empty URL \nResult: " +  validTester.isValid(""));
    }

    public void testPartition1(){
        int count = 1000;
        Random r = new Random();
        String tStr = "";
        char[] invalidChars = {'^', '[', ']', '`', '!', '\'', '(', ')', '*', '/', '_', '%', '/', '?', ':', '@', '&', '=',
            '$', ',', '"', '>', '<', '#', ';', '{', '}', '|', '\\' };
        UrlValidator validTester = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
        for (int i = 1; i < count; i++){
            boolean expected = true;
            tStr = "";
            for (int j = 0; j <3 ; j++){
                int testChar = r.nextInt(126-33) + 33;
                if (j == 0 ){
                    // Search ASCII alphabet
                    if (!(testChar >= 65 && testChar<= 90) && !(testChar >= 97 && testChar <= 122)){
                        expected &= false;
                    }
                }
                char[] tempChar = Character.toChars(testChar);
                if (new String(invalidChars).contains(Character.toString(tempChar[0]))){
                    expected &= false;
                }
                tStr += tempChar[0];
            }

            // URL
            tStr = tStr + "://bing.com";

            boolean result = validTester.isValid(tStr);

            assertEquals(expected, result);
            if (status) {
                if (result == expected) {
                    System.out.print('.');
                } else {
                    System.out.print('X');
                }
            }
        }
        if (status) {
            System.out.println();
        }

    }

    public void testPartition2(){
        int count = 1000;
        Random r = new Random();
        String protocol[] = { "http:", "ftp:", "smtp:", "mailto:", "file:",
            "news:", "telnet:"};

        String connector[] = {"//" } ;
        String terminator[] = {"/", ""};
        String tld[] = {".edu", ".gov", ".org", ".com", ".mil"};

        String testURL = "";

        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        try {
            assertTrue(validTester.isValid("http://www.google.com"));
            assertTrue(validTester.isValid("http://www.google.com/"));
        } catch (AssertionError ex) {
            System.out.println("Assertions failed.\n");
            System.exit(1);
        }

        System.out.print("Test tlds\n");
        for (int i = 0; i < count; i++){

            //let's test a set of good addresses
            String host[] = { "hotmail", "facebook", "bing", "apple", "msn", "html5",
                "adidas", "nike", "youtube", "twitter"};

            testURL = "http://" + host[i % host.length] + ".com";
            boolean expected = true;

            boolean result = validTester.isValid(testURL);
            assertEquals(result, expected);
            if (result == expected)
            {
                System.out.print(".");
                if ((i % 72) == 0)
                    System.out.print("\n");
            }
            else {
                System.out.print("X");
            }
        }

        System.out.print("IP\n");
        for (int i = 0; i < count; i++){

            int fourBytes[] = {0, 0, 0, 0};

            for (int j = 0; j < fourBytes.length; j++)
                fourBytes[j] = r.nextInt(255);

            String host = Integer.toString(fourBytes[0]) + "." +
            Integer.toString(fourBytes[1]) + "." +
            Integer.toString(fourBytes[2]) + "." +
            Integer.toString(fourBytes[3]);

            testURL = "http://" + host;
            boolean expected = true;

            boolean result = validTester.isValid(testURL);

            assertEquals(expected, result);
            if (result == expected){
                System.out.print(".");
                if ((i % 72) == 0)
                    System.out.print("\n");
            }
            else {
                System.out.print("X");
            }
        }

        // Random string
        System.out.print("\nRandom string\n");
        for (int i = 0; i < 1000; i++){

            String host = "";

            for (int j = 0; j < 10; j++){
                while (true){
                    int numero = r.nextInt(123 - 48) + 48;
                    if (j == 0) {
                        if (((numero >=65) && (numero <= 90)) || ((numero >= 97) && (numero <= 122))){
                            host = Character.toString((char) numero);
                            break;
                        }
                    }
                    else if (((numero >=65) && (numero <= 90)) || ((numero >= 97) && (numero <= 122)) || ((numero >= 48) && (numero <= 57))){
                        host = host + Character.toString((char) numero);
                        break;
                    }
                }
            }
            testURL = "http://" + host + ".com";
            boolean expected = true;

            boolean result = validTester.isValid(testURL);

            assertEquals(expected, result);
            if (result == expected) {
                System.out.print(".");
                if ((i % 72) == 0)
                    System.out.print("\n");
            }
            else {
                System.out.print("X");
            }

            int protocolNo = r.nextInt(protocol.length);
            int connectorNo = r.nextInt(connector.length);
            int terminatorNo = r.nextInt(terminator.length);
            int tldNo = r.nextInt(tld.length);

            testURL = protocol[protocolNo];
            testURL = testURL + connector[connectorNo];
            testURL = testURL + host;
            testURL = testURL + tld[tldNo];
            testURL = testURL + terminator[terminatorNo];

            result = validTester.isValid(testURL);

            assertEquals(expected, result);
            if (result == expected){
                System.out.print(".");
                if ((i % 72) == 0)
                    System.out.print("\n");
            }
            else {
                System.out.print("X");
            }

        }

        // Random string length
        System.out.print("\nRandom string length\n");
        for (int i = 0; i < 1000; i++){
            String host = "";
            for (int j = 0; j < r.nextInt(255 - 11) + 1; j++){
                while (true){
                    int numero = r.nextInt(123 - 48) + 48;
                    if (j == 0){
                        if (((numero >=65) && (numero <= 90)) || ((numero >= 97) && (numero <= 122))) {
                            host = Character.toString((char) numero);
                            break;
                        }
                    }
                    else if (((numero >=65) && (numero <= 90)) || ((numero >= 97) && (numero <= 122)) || ((numero >= 48) && (numero <= 57))) {
                        host = host + Character.toString((char) numero);
                        break;
                    }
                }
            }
            testURL = "http://" + host + ".com";
            boolean expected = true;

            boolean result = validTester.isValid(testURL);

            assertEquals(expected, result);
            if (result == expected){
                System.out.print(".");
                if ((i % 72) == 0)
                    System.out.print("\n");
            }
            else {
                System.out.print("X");
            }
        }
    }

    public void testPorts() {
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        ResultPair[] testUrlPort = {new ResultPair("", true),
            new ResultPair(":", false),
            new ResultPair(":-1", false),
            new ResultPair(":8", true),
            new ResultPair(":80", true),
            new ResultPair(":800", true),
            new ResultPair(":8000", true),
            new ResultPair(":65535", true),
            new ResultPair(":65536", false)
        };
        String url = "http://www.google.com";

        assertTrue(validTester.isValid(url));
        System.out.println("Testing Port Number Range");
        for (int i = 0; i < testUrlPort.length; i++) {
            System.out.println(url + testUrlPort[i].item + " \nExpected: " + testUrlPort[i].valid);
            System.out.println("Actual: " + validTester.isValid(url + testUrlPort[i].item) + "\n");
        }
    }


    public void testIsValid() {
        testIPv4();
        testUrl();
        testASCII();
        testIsNull();
        testIsValidQuery();
        testIsValidPath();
        testIsValidFragment();

    }

    public void testIPv4(){

        String tStr = "http://170.149.159.130";
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean result = validTester.isValid(tStr);
        boolean expected = true;
        try {
            assertEquals(expected, result);
        } catch (AssertionError ae) {
            if (expected != result)
                System.out.print("testIPv4 Failed base valid assertion\n");
            else
                System.out.print("testIPv4 passed base valid assertion\n");
        }

        tStr = "http://256.256.256.256";
        expected = false;
        System.out.println(tStr + result+expected);
        result = validTester.isValid(tStr);
        try{
            assertEquals(expected, result);
        }
        catch (AssertionError ae) {
            if (expected != result)
                System.out.print("testIPv4 Failed base invalid assertion\n");
            else
                System.out.print("testIPv4 passed base invalid assertion\n");
        }
        Random r = new Random();


        int count = 10000;
        for (int i = 0; i < count; i++){
            tStr = "http://";
            expected = true;
            for(int j = 0; j < 4; j++)
            {
                int number = r.nextInt(500);
                tStr = tStr + number;
                if (j != 3)
                    tStr = tStr + ".";

                if (number >255)
                    expected = false;
            }
            result = validTester.isValid(tStr);
            try {
                assertEquals(expected, result);
            } catch (AssertionError ae) {
                if ((expected != result) && (expected == true))
                    System.out.print("Expected == True: " + tStr);
                else if ((expected != result) && (expected == false))
                    System.out.print("Expected = False: " + tStr);
            }

        }



    }

    public void testUrl(){

        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String tStr = "http://www.bing.com";

        boolean expected = true;

        boolean result = validTester.isValid(tStr);
        assertEquals(expected, result);

        StringBuilder fuzzedString = new StringBuilder(tStr);
        fuzzedString.setCharAt(3, '#');

        expected = false;
        result = validTester.isValid(fuzzedString.toString());
        assertEquals(expected, result);

    }


    public void testASCII(){
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String nonASCIIString = "";

        for (int i = 0; i < 5; i++){
            nonASCIIString = nonASCIIString + "\\";
            nonASCIIString = nonASCIIString + "x";
            nonASCIIString = nonASCIIString + "0";
            nonASCIIString = nonASCIIString + Integer.toString(i);

        }

        boolean expected = false;

        boolean result = validTester.isValid(nonASCIIString);

        assertEquals(expected, result);
        if (result != expected) {
            System.out.println("\nASCII failed.");
        }
        else{
            System.out.println("\nASCII passed.");
        }

    }

    public void testIsNull(){
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String nullString = "";

        boolean expected = false;

        boolean result = validTester.isValid(nullString);

        assertEquals(expected, result);
        if (result != expected){
            System.out.println("\nNull failed");
        }
        else{
            System.out.println("\nNull passed");
        }

    }

    public void testIsValidQuery(){
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String tStr = "";

        ResultPair[] testQuery = {new ResultPair("?action=delete", true),
            new ResultPair("?foo=bar&bar=foo", true),
            new ResultPair("?=foo&bar=foo", false),
            new ResultPair("", true)
        };

        System.out.println("\nTesting queries...\n");
        System.out.println("First testing that http://www.google.com \nResult: " +  validTester.isValid("http://www.google.com"));

        for (int i = 0; i < testQuery.length; i++){
            tStr = "http://www.bing.com" + testQuery[i].item;
            System.out.println(tStr + " \nExpected: " + testQuery[i].valid);
            System.out.println("Actual: " + validTester.isValid(tStr) + "\n");
        }

    }

    public void testIsValidPath(){
        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String tStr = "";

        ResultPair[] testPath = {
            new ResultPair("/test1", true),
            new ResultPair("/foo123", true),
            new ResultPair("/$17", true),
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/foo/", true),
            new ResultPair("", true),
            new ResultPair("/foo/bar", true),
            new ResultPair("/test1//file", false)
        };

        System.out.println("\nTesting paths...\n");
        System.out.println("First testing that http://www.google.com \nResult: " +  validTester.isValid("http://www.google.com") + "\n");
        for (int i = 0; i < testPath.length; i++){
            tStr = "http://www.bing.com" + testPath[i].item;
            System.out.println(tStr + " \nExpected: " + testPath[i].valid);
            System.out.println("Actual: " + validTester.isValid(tStr) + "\n");
        }

    }

    public void testIsValidFragment(){
        String testFragmentString = "";

        ResultPair[] testFragment = {new ResultPair("test", true),
            new ResultPair("1", true),
            new ResultPair("*", true),
            new ResultPair("//", true),
            new ResultPair("http:/", true),
            new ResultPair("http:", true),
            new ResultPair("http/", true),
            new ResultPair(".", true),
            new ResultPair("abc", true),
            new ResultPair("foo", true),
            new ResultPair("", true)};

        ResultPair[] testNullFragment = {
            new ResultPair(null, true)};

        System.out.println("\nTesting fragments with default NO_FRAGMENTS option set to off...\n");

        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        for (int i = 0; i < testFragment.length; i++)
        {
            testFragmentString = testFragment[i].item;

            boolean result = validTester.isValidFragment(testFragmentString);

            System.out.println("\n \"" + testFragment[i].item + "\" \nExpected: " + testFragment[i].valid);
            System.out.println("Actual: " + result + "\n");
        }

        // TEST NULL
        System.out.println("\n \"" + testNullFragment[0].item + "\" \nExpected: " + testNullFragment[0].valid);
        System.out.println("Actual: " + validTester.isValidFragment(testNullFragment[0].item) + "\n");


        System.out.println("\nTesting NO_FRAGMENTS...\n");

        UrlValidator validTester2 = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);

        for (int i = 0; i < testFragment.length; i++){
            testFragmentString = testFragment[i].item;
            //run isValidFragment
            boolean result = validTester2.isValidFragment(testFragmentString);

            // False expected
            System.out.println("\n \"" + testFragment[i].item + "\" \nExpected: " + !testFragment[i].valid);             System.out.println("Actual: " + result + "\n");
        }

        //test null fragment
        System.out.println("\n \"" + testNullFragment[0].item + "\" \nExpected: " + testNullFragment[0].valid);
        System.out.println("Actual: " + validTester2.isValidFragment(testNullFragment[0].item) + "\n");

    }

    public void testOther(){

        UrlValidator validTester = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String tStr = "";
        int iterationNumber = 1;

        ResultPair[] testprotocol = {new ResultPair("http://", true),
            new ResultPair("ftp://", true),
            new ResultPair("mailto://", true),
            new ResultPair("ht4://", false),
            new ResultPair("http:/", false),
            new ResultPair("http:", false),
            new ResultPair("http/", false),
            new ResultPair("://", false),
            new ResultPair("https://", true),
            new ResultPair("", true)};

        ResultPair[] testAuthority = {new ResultPair("www.google.com", true),
            new ResultPair("wikipedia.org", true),
            new ResultPair("amazon.com", true),
            new ResultPair("0.0.0.0", true),
            new ResultPair("255.255.255.255", true),
            new ResultPair("256.256.256.256", false),
            new ResultPair("255.com", true),
            new ResultPair("1.2.3.4.5", false),
            new ResultPair("1.2.3.4.", false),
            new ResultPair("1.2.3", false),
            new ResultPair(".1.2.3.4", false),
            new ResultPair("abcde.", false),
            new ResultPair(".abc", false),
            new ResultPair("abcde", false),
            new ResultPair("", false)
        };
        ResultPair[] testPort = {new ResultPair("", true),
            new ResultPair(":", false),
            new ResultPair(":-1", false),
            new ResultPair(":8", true),
            new ResultPair(":80", true),
            new ResultPair(":800", true),
            new ResultPair(":8000", true),
            new ResultPair(":65535", true),
            new ResultPair(":65536", false)
        };

        ResultPair[] testPath = {new ResultPair("/test1", true),
            new ResultPair("/foo123", true),
            new ResultPair("/$17", true),
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/foo/", true),
            new ResultPair("", true),
            new ResultPair("/foo/bar", true),
            new ResultPair("/test1//file", false)
        };

        ResultPair[] testQuery = {new ResultPair("?action=delete", true),
            new ResultPair("?foo=bar&bar=foo", true),
            new ResultPair("?=foo&bar=foo", false),
            new ResultPair("", true)
        };


        System.out.println("Testing complete URLs");

        for (int protocolIndex = 0; protocolIndex < testprotocol.length; protocolIndex++){
            for (int authorityIndex = 0; authorityIndex < testAuthority.length; authorityIndex++){
                for (int portIndex = 0; portIndex < testPort.length; portIndex++){
                    for (int pathIndex = 0; pathIndex < testPath.length; pathIndex++){
                        for (int queryIndex = 0; queryIndex < testQuery.length; queryIndex++){
                            // URL test
                            tStr = testprotocol[protocolIndex].item + testAuthority[authorityIndex].item + testPort[portIndex].item + testPath[pathIndex].item + testQuery[queryIndex].item;

                            boolean expected = true;

                            if(!testprotocol[protocolIndex].valid  || !testAuthority[authorityIndex].valid  || !testPort[portIndex].valid  || !testPath[pathIndex].valid  || !testQuery[queryIndex].valid){
                                expected = false;
                            }

                            boolean result = validTester.isValid(tStr);

                            if (expected != result){
                                System.out.println("Test " + iterationNumber + ":\n");
                                System.out.println(tStr + " \nExpected: " + expected);
                                System.out.println("Actual: " + result + "\n");

                                System.out.println("protocol: "+ testprotocol[protocolIndex].item + ", " + testprotocol[protocolIndex].valid);
                                System.out.println("Authority: " + testAuthority[authorityIndex].item + ", " + testAuthority[authorityIndex].valid);
                                System.out.println("Port: " + testPort[portIndex].item + ", " + testPort[portIndex].valid);
                                System.out.println("Path: " + testPath[pathIndex].item + ", " + testPath[pathIndex].valid);
                                System.out.println("Query: " + testQuery[queryIndex].item + ", " + testQuery[queryIndex].valid);
                                System.out.println("\n");
                            }
                            iterationNumber++;
                        }
                    }
                }
            }
        }
    }
}
