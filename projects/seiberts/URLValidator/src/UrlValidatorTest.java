/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   /**********************************************************************************
    * Name: testManualTest()
    * Purpose: This function is maunally testing a complete URL. If the expected result
    * 			matches the actual results, then the test passes. Else, the test will
    * 			fail. The user is prompted with the test results.
    * Inputs: Uses manually inputed URL's to test the URL Validator
    * Outputs: Test results of those URL's tested 
    **********************************************************************************/
   
   
   public void testManualTest()
   {
	   System.out.println("----------------------------------------------------");
	   System.out.println("|****************** Manual Tests *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   System.out.println("Running Manual Tests...");

		//Create URL object that allows all Schemes 
	    //(https://commons.apache.org/proper/commons-validator/javadocs/api-1.5.1/org/apache/commons/validator/routines/UrlValidator.html)
	    UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		
	    //Begin manual testing of various URL's
	    System.out.println("\nTesting: http://www.reddit.com/");
		if(urlVal.isValid("http://www.reddit.com/") == true)
		{
			System.out.println("Test passed");
		}
		else
		{
			System.out.println("Test Failed");
		}
		
		System.out.println("\nhttps://www.reddit.com/homePage_1-3.html");		
		if(urlVal.isValid("https://www.reddit.com/homePage_1-3.html"))
		{
			System.out.println("Test passed");
		}
		else
		{
			System.out.println("Test Failed");
		}	
		
		System.out.println("\nhttps://www.reddit.com/homePage.html");		
		if(urlVal.isValid("https://www.reddit.com/homePage.html"))
		{
			System.out.println("Test passed");
		}
		else
		{
			System.out.println("Test Failed");
		}

		System.out.println("\nhttps://www.oregon_state.edu/");		
		if(urlVal.isValid("https://www.oregon_state.edu/"))
		{
			System.out.println("Test passed");
		}
		else
		{
			System.out.println("Test Failed as expected");
		}

		System.out.println("\nfttps://www.reddit.com/homePage.html");	
		if(urlVal.isValid("fttps://www.reddit.com/homePage.html"))
		{
			System.out.println("Test passed");
		}
		else
		{
			System.out.println("Test Failed");
		}

		System.out.println("\nhttps://www.oregon.gov/home_0_1_2.html");	
		if(urlVal.isValid("https://www.oregon.gov/home_0_1_2.html"))
		{
			System.out.println("Test passed");
		}
		else
		{
			System.out.println("Test Failed");
		}
		 System.out.println("----------------------------------------------------");
		 System.out.println("|*************** End of Manual Tests ***************|");
		 System.out.println("----------------------------------------------------");
	   
   }
   
   /**********************************************************************************
    * Name: testYourFirstPartition()
    * Purpose: This function is testing the schemes of the URL. If the expected result
    * 			matches the actual results, then the test passes. Else, the test will
    * 			fail. The user is prompted with the test results.
    * Inputs: Uses ResultPair[] schemes that contain various schemes
    * Outputs: Test results of those schemes tested 
    **********************************************************************************/
   
   public void testYourFirstPartition()
   {
	   //True URLS for testing from https://www.w3.org/Addressing/URL/url-spec.txt
	   
	   //Create UrlValidator Object that allows all schemes to be used.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Create initial URL to be parsed with tested scheme
	   String initialURL = "www.oregonstate.edu";
	   
	 //Create String to hold combined URL for testing
	   String combinedURL;
	   
	   //Create Boolean Variable to hold the result of the test
	   boolean result;
	   
	   //Prompt user with testing schemes
	   System.out.println("----------------------------------------------------");
	   System.out.println("|*************** Testing Schemes *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   //Loop through all the schemes located in ResultPair[] schemes below
	   for (int i = 0; i < schemes.length; i++) 
	   {
			   //Combine to create a whole URL to be tested
		   	   combinedURL = schemes[i].item + initialURL;
			   
		   	   //Set the expected validity of the scheme tested
		   	   result = urlVal.isValid(combinedURL);
			   
		   	   //If the tests passes, prompt the user with the actual and expected results
		   	   if (result == schemes[i].valid)
			   {
				   System.out.println("Test Passed: Scheme used " + schemes[i].item + " || Actual Result: " + result + " ||  Expected Result: " + schemes[i].valid);
			   } 
		   	   //If the tests fails, prompt the user with the actual and expected results
		   	   else 
			   {
				   System.out.println("Test Failed: Scheme used " + schemes[i].item + " || Actual Result: " + result + " ||  Expected Result: " +  schemes[i].valid);
			   }
			
		}

	   //Prompt the user with the end of testing
	   System.out.println("----------------------------------------------------");
	   System.out.println("|************* End of Scheme Test ******************|");
	   System.out.println("----------------------------------------------------");
   }
  
   /**********************************************************************************
    * Name: testYourSecondPartition()
    * Purpose:  This function tests ports of a URL. Ports range 0 - 65535 as 
    * 			valid ports. If the expected result matches the actual results, then 
    * 			the test passes. Else, the test will fail. The user is prompted with 
    * 			the test results.
    * Inputs:  Uses ResultPair[] ports that contain various schemes
    * Outputs: Test results of those ports tested 
    * Website: http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml
    **********************************************************************************/
   public void testYourSecondPartition()
   {
 //True URLS for testing from https://www.w3.org/Addressing/URL/url-spec.txt
	   
	   //Create UrlValidator Object that allows all schemes to be used.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Create initial URL to be parsed with tested scheme
	   String initialURL = "http://www.oregonstate.edu";
	   
	 //Create String to hold combined URL for testing
	   String combinedURL;
	   
	   //Create Boolean Variable to hold the result of the test
	   boolean result;
	   
	   //Prompt user with testing schemes
	   System.out.println("----------------------------------------------------");
	   System.out.println("|*************** Testing Ports *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   //Loop through all the schemes located in ResultPair[] schemes below
	   for (int i = 0; i < ports.length; i++) 
	   {
			   //Combine to create a whole URL to be tested
		   	   combinedURL = initialURL + ports[i].item;
			   
		   	   //Set the expected validity of the scheme tested
		   	   result = urlVal.isValid(combinedURL);
			   
		   	   //If the tests passes, prompt the user with the actual and expected results
		   	   if (result == ports[i].valid)
			   {
				   System.out.println("Test Passed: port used " + ports[i].item + " || Actual Result: " + result + " ||  Expected Result: " + ports[i].valid);
			   } 
		   	   //If the tests fails, prompt the user with the actual and expected results
		   	   else 
			   {
				   System.out.println("Test Failed: port used " + ports[i].item + " || Actual Result: " + result + " ||  Expected Result: " +  ports[i].valid);
			   }
			
		}

	   //Prompt the user with the end of testing
	   System.out.println("----------------------------------------------------");
	   System.out.println("|************* End of Port Test ******************|");
	   System.out.println("----------------------------------------------------");
   }
 
   /**********************************************************************************
    * Name: testYourThirdPartition()
    * Purpose:  This function tests a path of a URL.
    * 			If the expected result matches the actual results, then 
    * 			the test passes. Else, the test will fail. The user is prompted with 
    * 			the test results.
    * Inputs:  Uses ResultPair[] paths that contain various schemes
    * Outputs: Test results of those ports tested 
    * Website: https://www.w3.org/Addressing/URL/url-spec.txt
    **********************************************************************************/
   public void testYourThirdPartition()
   {
     
	   //Create UrlValidator Object that allows all schemes to be used.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Create initial URL to be parsed with tested scheme
	   String initialURL = "http://www.oregonstate.edu";
	   
	 //Create String to hold combined URL for testing
	   String combinedURL;
	   
	   //Create Boolean Variable to hold the result of the test
	   boolean result;
	   
	   //Prompt user with testing schemes
	   System.out.println("----------------------------------------------------");
	   System.out.println("|*************** Testing Paths *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   //Loop through all the schemes located in ResultPair[] schemes below
	   for (int i = 0; i < paths.length; i++) 
	   {
			   //Combine to create a whole URL to be tested
		   	   combinedURL = initialURL + paths[i].item;
			   
		   	   //Set the expected validity of the scheme tested
		   	   result = urlVal.isValid(combinedURL);
			   
		   	   //If the tests passes, prompt the user with the actual and expected results
		   	   if (result == paths[i].valid)
			   {
				   System.out.println("Test Passed: path used " + paths[i].item + " || Actual Result: " + result + " ||  Expected Result: " + paths[i].valid);
			   } 
		   	   //If the tests fails, prompt the user with the actual and expected results
		   	   else 
			   {
				   System.out.println("Test Failed: path used " + paths[i].item + " || Actual Result: " + result + " ||  Expected Result: " +  paths[i].valid);
			   }
			
		}
	   //Prompt the user with the end of testing
	   System.out.println("----------------------------------------------------");
	   System.out.println("|************* End of Path Test ******************|");
	   System.out.println("----------------------------------------------------");
}
   /**********************************************************************************
    * Name: testYourFourthPartition()
    * Purpose:  This function tests the TLDs of a URL.
    * 			If the expected result matches the actual results, then 
    * 			the test passes. Else, the test will fail. The user is prompted with 
    * 			the test results.
    * Inputs:  Uses ResultPair[] TLDSs that contain various schemes
    * Outputs: Test results of those TLDs tested 
    * Website: https://www.w3.org/Addressing/URL/url-spec.txt
    **********************************************************************************/
   public void testYourFourthPartition()
   {
     
	   //Create UrlValidator Object that allows all schemes to be used.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Create initial URL to be parsed with tested scheme
	   String initialURL = "http://www.oregonstate.";
	   
	   //Create String to hold combined URL for testing
	   String combinedURL;
	   
	   //Create Boolean Variable to hold the result of the test
	   boolean result;
	   
	   //Prompt user with testing schemes
	   System.out.println("----------------------------------------------------");
	   System.out.println("|*************** Testing TLD *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   //Loop through all the tlds located in ResultPair[] tlds below
	   for (int i = 0; i < tlds.length; i++) 
	   {
			   //Combine to create a whole URL to be tested
		   	   combinedURL = initialURL + tlds[i].item;
			   
		   	   //Set the expected validity of the scheme tested
		   	   result = urlVal.isValid(combinedURL);
			   
		   	   //If the tests passes, prompt the user with the actual and expected results
		   	   if (result == tlds[i].valid)
			   {
				   System.out.println("Test Passed: TLDS used " + tlds[i].item + " || Actual Result: " + result + " ||  Expected Result: " + tlds[i].valid);
			   } 
		   	   //If the tests fails, prompt the user with the actual and expected results
		   	   else 
			   {
				   System.out.println("Test Failed: TLDS used " + tlds[i].item + " || Actual Result: " + result + " ||  Expected Result: " +  tlds[i].valid);
			   }
			
		}
	   //Prompt the user with the end of testing
	   System.out.println("----------------------------------------------------");
	   System.out.println("|************* End of TLD Test ******************|");
	   System.out.println("----------------------------------------------------");
}
   
   /**********************************************************************************
    * Name: testYourFifthPartition()
    * Purpose:  This function tests the domain of a URL.
    * 			If the expected result matches the actual results, then 
    * 			the test passes. Else, the test will fail. The user is prompted with 
    * 			the test results.
    * Inputs:  Uses ResultPair[] TLDSs that contain various schemes
    * Outputs: Test results of those TLDs tested 
    * Website: https://www.w3.org/Addressing/URL/url-spec.txt
    **********************************************************************************/
   public void testYourFifthPartition()
   {
     
	   //Create UrlValidator Object that allows all schemes to be used.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String schemePart = "http://";
	   
	   //Create initial URL to be parsed with tested scheme
	   String initialURL = ".com";
	   
	   //Create String to hold combined URL for testing
	   String combinedURL;
	   
	   //Create Boolean Variable to hold the result of the test
	   boolean result;
	   
	   //Prompt user with testing schemes
	   System.out.println("----------------------------------------------------");
	   System.out.println("|*************** Testing Domain Name *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   //Loop through all the domains located in ResultPair[] domains below
	   for (int i = 0; i < domains.length; i++) 
	   {
			   //Combine to create a whole URL to be tested
		   	   combinedURL = schemePart + domains[i].item + initialURL;
			   
		   	   //Set the expected validity of the scheme tested
		   	   result = urlVal.isValid(combinedURL);
			   
		   	   //If the tests passes, prompt the user with the actual and expected results
		   	   if (result == domains[i].valid)
			   {
				   System.out.println("Test Passed: domains used " + domains[i].item + " || Actual Result: " + result + " ||  Expected Result: " + domains[i].valid);
			   } 
		   	   //If the tests fails, prompt the user with the actual and expected results
		   	   else 
			   {
				   System.out.println("Test Failed: domains used " + domains[i].item + " || Actual Result: " + result + " ||  Expected Result: " +  domains[i].valid);
			   }
			
		}
	   //Prompt the user with the end of testing
	   System.out.println("----------------------------------------------------");
	   System.out.println("|************* End of Domain Test ******************|");
	   System.out.println("----------------------------------------------------");
}
   
   /**********************************************************************************
    * Name: testYourSixthPartition()
    * Purpose:  This function tests the query of a URL.
    * 			If the expected result matches the actual results, then 
    * 			the test passes. Else, the test will fail. The user is prompted with 
    * 			the test results.
    * Inputs:  Uses ResultPair[] queries that contain various query
    * Outputs: Test results of those query tested 
    * 
    **********************************************************************************/
   public void testYourSixthPartition()
   {
     
	   //Create UrlValidator Object that allows all schemes to be used.
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	  
	   //Create initial URL to be parsed with tested scheme
	   String initialURL = "http://www.oregonstate.edu/login";
	   
	   //Create String to hold combined URL for testing
	   String combinedURL;
	   
	   //Create Boolean Variable to hold the result of the test
	   boolean result;
	   
	   //Prompt user with testing schemes
	   System.out.println("----------------------------------------------------");
	   System.out.println("|*************** Testing queries *******************|");
	   System.out.println("----------------------------------------------------");
	   
	   //Loop through all the queries located in ResultPair[] queries below
	   for (int i = 0; i < queries.length; i++) 
	   {
			   //Combine to create a whole URL to be tested
		   	   combinedURL = initialURL + queries[i].item;
			   
		   	   //Set the expected validity of the scheme tested
		   	   result = urlVal.isValid(combinedURL);
			   
		   	   //If the tests passes, prompt the user with the actual and expected results
		   	   if (result == queries[i].valid)
			   {
				   System.out.println("Test Passed: queries used " + queries[i].item + " || Actual Result: " + result + " ||  Expected Result: " + queries[i].valid);
			   } 
		   	   //If the tests fails, prompt the user with the actual and expected results
		   	   else 
			   {
				   System.out.println("Test Failed: queries used " + queries[i].item + " || Actual Result: " + result + " ||  Expected Result: " +  queries[i].valid);
			   }
			
		}
	   //Prompt the user with the end of testing
	   System.out.println("----------------------------------------------------");
	   System.out.println("|************* End of Query Test ******************|");
	   System.out.println("----------------------------------------------------");
}
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   /*
   public void testAnyOtherUnitTest()
   {
	   
   }
   */
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   /* Some protocols used from https://en.wikipedia.org/wiki/Lists_of_network_protocols */
   static ResultPair[] queries = {
		   new ResultPair("?userName=cs362", true),
		   new ResultPair("?pass= ", false),
		   new ResultPair("? = ", false),
		   new ResultPair("?", false),
		   new ResultPair("?userName=cs362;password=osu", true),
		   new ResultPair("?=password=osu", false)
   };
   
   static ResultPair[] domains = {
		   new ResultPair("www.oregon", true),
		   new ResultPair("www.oregonstate", true),
		   new ResultPair("www.oregon state", false),
		   new ResultPair("www.catInTheHat", true),
		   new ResultPair("www.google.", false),
		   new ResultPair("www..iLikeTurtles", false),
		   new ResultPair("www.jobs.[", false),
		   new ResultPair("www.lotsOfTrees./", false),
		   new ResultPair("www. .", false),
		   new ResultPair("www.www.www.", true),
		   new ResultPair("www/www/www.", false),
		   new ResultPair("www*.", false)
		   
  };
   
   static ResultPair[] tlds = {
		   new ResultPair(".shouldNotWork", false),
		   new ResultPair(".aaa", false),
		   new ResultPair(".zz", false),
		   new ResultPair(".@#$%com", false),
		   new ResultPair("com", true),
		   new ResultPair("cat", true),
		   new ResultPair("coop", true),
		   new ResultPair("info", true),
		   new ResultPair("jobs", true),
		   new ResultPair("mobi", true),
		   new ResultPair("museum", true),
		   new ResultPair("net", true), 
		   new ResultPair("org", true),
		   new ResultPair("tel", true),
		   new ResultPair("travel", true),
		   new ResultPair("gov", true),
		   new ResultPair("edu", true),
		   new ResultPair("mil", true),
		   new ResultPair("int", true),
		   new ResultPair("ac", true),
		   new ResultPair("ad", true),
		   new ResultPair("ae", true),
		   new ResultPair("as", true),
		   new ResultPair("au", true),
		   new ResultPair("be", true),
		   new ResultPair("bf", true),
		   new ResultPair("comm", false),
		   new ResultPair(".com", false),
		   new ResultPair(" ", false),
		   new ResultPair("communication", false),
		   new ResultPair("mil edu", false),
		   new ResultPair("trip", false),
		   new ResultPair("oregon", false),
		   new ResultPair("guv", false),
		   new ResultPair("tree", false),
		   new ResultPair("beav", false),
		   new ResultPair("train", false),
		   new ResultPair("http://", false)		   
   };
   
   static ResultPair[] paths = {
		   new ResultPair("/test", true),
		   new ResultPair("/test/test", true),
		   new ResultPair("/test/", true),
		   new ResultPair("/test/test/", true),
		   new ResultPair("//test", false),
		   new ResultPair("/ test", false),
		   new ResultPair("/#test", false),
		   new ResultPair("//test//", false),
		   new ResultPair("/../", false),
		   new ResultPair("", true)
	   };

   static ResultPair[] ports = 
	   { 
		   new ResultPair(":1024", true),
		   new ResultPair(":0", true),
		   new ResultPair(":65535", true),
		   new ResultPair(": ", false),
		   new ResultPair(":Zero", false),
		   new ResultPair(":755", true),
		   new ResultPair(":65534", true),
		   new ResultPair(":33s3", false)
	   };
   
   static ResultPair[] schemes = 
	   {
		   new ResultPair("http://", true),
		   new ResultPair("https://", true),
		   new ResultPair("ftp://", true),
		   new ResultPair("3pO://", false),
		   new ResultPair("telnet://", false),
		   new ResultPair("http: //", false),
		   new ResultPair("     ", false),
		   new ResultPair("fttp://", false),
		   new ResultPair("cs362://", false),
		   new ResultPair("cs:/", false)
	   };
   

   

}
