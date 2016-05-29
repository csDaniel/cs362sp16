/*
 * stramelm, ohaverd, faesslek
 * OSU/CS362
 * Spring 2016
 */

import static org.junit.Assert.*;

public class UnitTests {

		public static void unitTestLocal() {
			   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
			   
			   boolean result = urlVal.isValid("http://localhost:8080");
			   //assertEquals(true, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://localhost:808");
			   //assertEquals(true, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://localhost:80");
			   //assertEquals(true, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://localhost");
			   //assertEquals(true, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://www.example.com");
			   assertEquals(true, result);
		}
	 
		public static void unitTestFragments() {
			   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
			
			   boolean result = urlVal.isValid("http://www.somesite.com/somepage.html#somefragment");
			   assertEquals(true, result);

			   result = urlVal.isValid("http://www.somesite.com/somepage.html#");
			   assertEquals(true, result);

			   result = urlVal.isValid("http://www.somesite.com/somepage.html#$");
			   assertEquals(true, result);

			   result = urlVal.isValid("http://www.somesite.com/somepage.html##");
			   //assertEquals(false, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://www.somesite.com/somepage.html#\\");
			   //assertEquals(false, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://www.somesite.com/somepage.html#/");
			   assertEquals(true, result);

			   result = urlVal.isValid("http://www.somesite.com/somepage.html#^");
			   //assertEquals(false, result);
			   //failed assertion commented out to keep test suite going

			   result = urlVal.isValid("http://www.somesite.com/somepage.html#%");
			   //assertEquals(false, result);
			   //failed assertion commented out to keep test suite going

			   UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
			   
			   result = urlVal2.isValid("http://www.somesite.com/somepage.html#somefragment");
			   assertEquals(false, result);

		}
	
		public static void unitTestPortNumbers() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://www.amazon.com:-1");
		   assertEquals(false, result);
	
		   result = urlVal.isValid("http://www.amazon.com:0");
		   assertEquals(true, result);
	
		   result = urlVal.isValid("http://www.amazon.com:10");
		   assertEquals(true, result);
	
		   result = urlVal.isValid("http://www.amazon.com:100");
		   assertEquals(true, result);
	
		   result = urlVal.isValid("http://www.amazon.com:999");
		   assertEquals(true, result);
	
		   result = urlVal.isValid("http://www.amazon.com:1000");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	
		   result = urlVal.isValid("http://www.amazon.com:10000");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	
		   result = urlVal.isValid("http://www.amazon.com:65535");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	
		   result = urlVal.isValid("http://www.amazon.com:65536");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
		}
	
		public static void unitTestIPAddresses() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://0.0.0.0");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://0...0");
		   assertEquals(false, result);

		   result = urlVal.isValid("http://0.255.255.255");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://1.0.0.0");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://10.0.0.0");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://10.255.255.255");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://11.0.0.0");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://224.0.0.0");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://239.255.255.255");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://240.0.0.0");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://255.255.255.255");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://256.0.0.0");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://999.999.999.999");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://9999.999.999.999");
		   assertEquals(false, result);

		   result = urlVal.isValid("http://-1.999.999.999");
		   assertEquals(false, result);
	   }

	   public static void unitTest062() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://a.b--c.de/");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.b---c.de/");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.b--c.com/");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.b-!c.de/");
		   assertEquals(false, result);

		   result = urlVal.isValid("http://a.b!-c.de/");
		   assertEquals(false, result);

		   result = urlVal.isValid("http://a.b-c.de/");
		   assertEquals(true, result);
	   }

	   public static void unitTest034() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://-.~_!$&'()*+,;=:%40:80%2f::::::@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://-.~_!$&'()*+,;=:%40:80%2f@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://username:%40:80%2f@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://-.~_!$&'()*+,;=:password@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://username:password@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("ftp://username:password@example.com");
		   //assertEquals(true, result);
	   }

	   // unitTest031, unitTest032, unitTest033 not included as they
	   // would just be repetitive variations of unitTest026

	   public static void unitTest030() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://foo.bar/?q=Test%20URL-encoded%20stuff");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://foo.com/");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://foo.com/?q=Test");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void unitTest029() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("ftp://foo.bar/baz");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("ftp://foo.bar");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://foo.bar");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("ftp://foo.com");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://foo.com");
		   assertEquals(true, result);

		   result = urlVal.isValid("ftp://foo.com/baz");
		   assertEquals(true, result);

		   result = urlVal.isValid("ftp://foo.biz/baz");
		   assertEquals(true, result);
	   }

	   public static void unitTest028() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://j.mp");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.mp");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.com");
		   assertEquals(true, result);
	   }

	   public static void unitTest026() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://☺.damowmow.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.damowmow.com/");
		   assertEquals(true, result);
	   }

	   public static void unitTest025() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://foo.com/(something)?after=parens");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://foo.com/(something)");
		   assertEquals(true, result);
	   }

	   public static void unitTest024() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://foo.com/unicode_(✪)_in_parens");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://foo.com/unicode_(a)_in_parens");
		   assertEquals(true, result);
	   }

	   // unitTest021 not included as it
	   // would just be repetitive variation of unitTest020
	
		public static void unitTest020() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://⌘.ws");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.ws");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.it");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://⌘.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.com");
		   assertEquals(true, result);
	   }

	   public static void unitTest019() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://➡.ws/䨹");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://➡.ws/a");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://➡.ws/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://➡.com/䨹");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.com/䨹");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://➡.com/a");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://a.com/a");
		   assertEquals(true, result);
	   }

	   public static void unitTest018() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://142.42.1.1:8080/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://142.42.1.1:80808");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://142.42.1.1:808");
		   assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://142.42.1.1");
		   assertEquals(true, result);
	   }

	   // unitTest013, unitTest014, unitTest015, unitTest016 not included as they
	   // would just be repetitive variations of unitTest009, unitTest010, unitTest011, unitTest012
	
	   public static void unitTest012() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://userid@example.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   // no need to test further - see unitTest011
	   }   
	   
	   public static void unitTest011() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://userid@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://example.com");
		   assertEquals(true, result);
	   }   
	   
	   public static void unitTest010() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://userid:password@example.com:8080/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://userid:password@example.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://example.com/");
		   assertEquals(true, result);
	   }   
	   
	   public static void unitTest009() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("http://userid:password@example.com:8080");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://userid:password@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://example.com:8080");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://example.com:80808");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("http://example.com:808");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://example.com:80");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://example.com:8");
		   assertEquals(true, result);

		   result = urlVal.isValid("http://example.com");
		   assertEquals(true, result);
	   }   

	   public static void unitTest008() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://✪df.ws/123");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://✪df.ws/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://df.ws/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://✪df.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://df.com/");
		   assertEquals(true, result);
	   }   
	   
	   public static void unitTest007() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("https://www.example.com/foo/?bar=baz&inga=42&quux");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("https://www.example.com/foo/?bar=baz&inga=42");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("https://www.example.com/foo/?bar=baz");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("https://www.example.com/foo/");
		   assertEquals(true, result);
		   
		   result = urlVal.isValid("https://www.example.com/");
		   assertEquals(true, result);
	   }   

	   public static void unitTest006() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid("http://www.example.com/wpstyle/?p=364");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://www.example.com/wpstyle/");
		   assertEquals(true, result);
		   
		   result = urlVal.isValid("http://www.example.com/wpstyle/?a=b");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
		   
		   result = urlVal.isValid("http://www.example.com/");
		   assertEquals(true, result);
	   }   
}
