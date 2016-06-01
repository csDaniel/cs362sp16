/*
 * stramelm, ohaverd, faesslek
 * OSU/CS362
 * Spring 2016
 */

import static org.junit.Assert.*;

public class PartitionTests {
	
		// N represents all possible inputs to URLValidator().isValid()
	    // N is the set of all possible strings
	    // (we will split this into sub-partitions)
	 
		// N1 is the partition that is all possible strings that DO NOT start with a letter character
		public static void partitionTestN1() {
			UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
			boolean result = urlVal.isValid("$ttp");
			assertEquals(false, result);

			result = urlVal.isValid("#ttp");
			assertEquals(false, result);

			result = urlVal.isValid("!ttp");
			assertEquals(false, result);
		}

		// N2 is the partition that is all possible strings that DO start with a letter character
	    // (we will split this into sub-partitions)
		
		// N2a is the partition that is all possible strings that DO start with a letter character
		//     and DO NOT contain the string '://'
		public static void partitionTestN2a() {
			UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
			boolean result = urlVal.isValid("http");
			assertEquals(false, result);

			result = urlVal.isValid("ftp");
			assertEquals(false, result);
		}

		// N2b is the partition that is all possible strings that DO start with a letter character
		//     and DO contain the string '://'
	    // (we will split this into sub-partitions)

		// N2b1 is the partition that is all possible strings that DO start with a letter character
		//     and DO contain the string '://' but DO NOT contain a '.' character after the string '://'
		public static void partitionTestN2b1() {
			UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
			boolean result = urlVal.isValid("http://somehost");
			assertEquals(false, result);

			result = urlVal.isValid("ftp://somehost");
			assertEquals(false, result);
		}

		// N2b2 is the partition that is all possible strings that DO start with a letter character
		//     and DO contain the string '://' and DO contain a '.' character after the string '://'
	    // (we will split this into sub-partitions)

		// N2b2a is the partition that is all possible strings that DO start with a letter character
		//     and DO contain the string '://' and DO contain a '.' character after the string '://'
		//     but DO NOT contain a letter or number character after the '.' character
		public static void partitionTestN2b2a() {
			UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
			boolean result = urlVal.isValid("http://somehost.");
			assertEquals(false, result);

			result = urlVal.isValid("ftp://somehost.");
			assertEquals(false, result);
		}
	
		// N2b2b is the partition that is all possible strings that DO start with a letter character
		//     and DO contain the string '://' and DO contain a '.' character after the string '://'
		//     and DO contain a letter or number character after the '.' character
	    // (we will split this into sub-partitions)

		// ... and on ...
		// ... and on ...
		// ... and on ...
		
		// to keep this from going forever, we'll define a final partition - though to be fair there isn't
		// enough equivalence of every URL in this partition to declare that they are all good or bad just because
		// one or two are good or bad, but I think we've demonstrated our knowledge of the purpose of
		// equivalence partition testing
		public static void partitionTestN2b2b() {
			UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
			boolean result = urlVal.isValid("http://somehost.123");
			assertEquals(false, result);

			result = urlVal.isValid("http://somehost.com");
			assertEquals(true, result);
		}
}
