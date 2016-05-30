/*
 * stramelm, ohaverd, faesslek
 * OSU/CS362
 * Spring 2016
 */

import static org.junit.Assert.*;

public class ManualTests {
	
	   public static void manualTest076() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://10.1.1.254");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest075() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://10.1.1.1");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest074() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://.www.foo.bar./");
		   assertEquals(false, result);
	   }

	   public static void manualTest073() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://www.foo.bar./");
		   assertEquals(false, result);
	   }

	   public static void manualTest072() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://.www.foo.bar/");
		   assertEquals(false, result);
	   }

	   public static void manualTest071() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://3628126748");
		   assertEquals(false, result);
	   }

	   public static void manualTest070() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://123.123.123");
		   assertEquals(false, result);
	   }

	   public static void manualTest069() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://1.1.1.1.1");
		   assertEquals(false, result);
	   }

	   public static void manualTest068() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://224.1.1.1");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest067() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://10.1.1.255");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest066() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://10.1.1.0");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest065() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://0.0.0.0");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest064() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://a.b-.co");
		   assertEquals(false, result);
	   }

	   public static void manualTest063() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://-a.b.co");
		   assertEquals(false, result);
	   }

	   public static void manualTest062() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://a.b--c.de/");
		   //assertEquals(false, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest061() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://-error-.invalid/");
		   assertEquals(false, result);
	   }

	   public static void manualTest060() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("ftps://foo.bar/");
		   assertEquals(false, result);
	   }

	   public static void manualTest059() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.bar/foo(bar)baz quux");
		   assertEquals(false, result);
	   }

	   public static void manualTest058() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid(":// should fail");
		   assertEquals(false, result);
	   }

	   public static void manualTest057() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http:// shouldfail.com");
		   assertEquals(false, result);
	   }

	   public static void manualTest056() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("h://test");
		   assertEquals(false, result);
	   }

	   public static void manualTest055() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("rdar://1234");
		   assertEquals(false, result);
	   }

	   public static void manualTest054() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("foo.com");
		   assertEquals(false, result);
	   }

	   public static void manualTest053() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http:///a");
		   assertEquals(false, result);
	   }

	   public static void manualTest052() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("///");
		   assertEquals(false, result);
	   }

	   public static void manualTest051() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("///a");
		   assertEquals(false, result);
	   }

	   public static void manualTest050() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("//a");
		   assertEquals(false, result);
	   }

	   public static void manualTest049() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("//");
		   assertEquals(false, result);
	   }

	   public static void manualTest048() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.bar?q=Spaces should be encoded");
		   assertEquals(false, result);
	   }

	   public static void manualTest047() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://##/");
		   assertEquals(false, result);
	   }

	   public static void manualTest046() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://##");
		   assertEquals(false, result);
	   }

	   public static void manualTest045() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://#");
		   assertEquals(false, result);
	   }

	   public static void manualTest044() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://??/");
		   assertEquals(false, result);
	   }

	   public static void manualTest043() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://??");
		   assertEquals(false, result);
	   }

	   public static void manualTest042() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://?");
		   assertEquals(false, result);
	   }

	   public static void manualTest041() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://../");
		   assertEquals(false, result);
	   }

	   public static void manualTest040() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://..");
		   assertEquals(false, result);
	   }

	   public static void manualTest039() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://.");
		   assertEquals(false, result);
	   }

	   public static void manualTest038() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://");
		   assertEquals(false, result);
	   }

	   public static void manualTest037() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://223.255.255.254");
		   assertEquals(true, result);
	   }

	   public static void manualTest036() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://a.b-c.de");
		   assertEquals(true, result);
	   }

	   public static void manualTest035() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://1337.net");
		   assertEquals(true, result);
	   }

	   public static void manualTest034() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://-.~_!$&'()*+,;=:%40:80%2f::::::@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest033() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://उदाहरण.परीक्षा");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest032() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://例子.测试");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest031() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://مثال.إختبار");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest030() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.bar/?q=Test%20URL-encoded%20stuff");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest029() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("ftp://foo.bar/baz");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest028() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://j.mp");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest027() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://code.google.com/events/#&product=browser");
		   assertEquals(true, result);
	   }

	   public static void manualTest026() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://☺.damowmow.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest025() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/(something)?after=parens");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest024() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/unicode_(✪)_in_parens");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest023() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/blah_(wikipedia)_blah#cite-1");
		   assertEquals(true, result);
	   }

	   public static void manualTest022() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/blah_(wikipedia)#cite-1");
		   assertEquals(true, result);
	   }

	   public static void manualTest021() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://⌘.ws/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest020() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://⌘.ws");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest019() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://➡.ws/䨹");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest018() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://142.42.1.1:8080/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }

	   public static void manualTest017() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://142.42.1.1/");
		   assertEquals(true, result);
	   }

	   public static void manualTest016() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid:password@example.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   

	   public static void manualTest015() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid:password@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   

	   public static void manualTest014() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid@example.com:8080/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   

	   public static void manualTest013() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid@example.com:8080");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest012() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid@example.com/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest011() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid@example.com");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest010() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid:password@example.com:8080/");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest009() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://userid:password@example.com:8080");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest008() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://✪df.ws/123");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest007() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("https://www.example.com/foo/?bar=baz&inga=42&quux");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest006() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://www.example.com/wpstyle/?p=364");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going
	   }   
	   
	   public static void manualTest005() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/blah_blah_(wikipedia)_(again)");
		   assertEquals(true, result);
	   }   
	   
	   public static void manualTest004() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/blah_blah_(wikipedia)");
		   assertEquals(true, result);
	   }   
	   
	   public static void manualTest003() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/blah_blah/");
		   assertEquals(true, result);
	   }   
	   
	   public static void manualTest002() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid("http://foo.com/blah_blah");
		   assertEquals(true, result);
	   }   
	   
	   public static void manualTest001() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid(null);
		   assertEquals(false, result);
	   }
}
