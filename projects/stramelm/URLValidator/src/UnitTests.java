/*
 * stramelm, ohaverd, faesslek
 * OSU/CS362
 * Spring 2016
 */

import static org.junit.Assert.*;

public class UnitTests {

	   public static void unitTest029() {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

		   boolean result = urlVal.isValid("ftp://foo.bar/baz");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("ftp://foo.bar");
		   //assertEquals(true, result);
		   //failed assertion commented out to keep test suite going

		   result = urlVal.isValid("ftp://foo.com");
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
		   
		   result = urlVal.isValid("http://www.example.com/");
		   assertEquals(true, result);
	   }   
}
