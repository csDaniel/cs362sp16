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


import java.util.Random;

import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   @SuppressWarnings("unused")
private boolean printStatus = false;
   @SuppressWarnings("unused")
private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   	boolean testVal;
	   
	   	//URL Scheme Test
	   	UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);  
	   	System.out.println("Test URL Schemes");
	   	System.out.println("____________________________");
	   	System.out.println();
	   
	   		System.out.println("TEST URL: http://www.google.com");
	   		testVal = urlVal.isValid("http://www.google.com");
	   		System.out.println("Expected = true, Tested = " + testVal);
	   		if(testVal == true)
	   			System.out.println("URL TEST = PASS");
	   		else
	   			System.out.println("URL TEST = FAIL");
	   		System.out.println();
	   		
	   		System.out.println("TEST URL: http://ww.google.com");
	   		testVal = urlVal.isValid("http://ww.google.com");
	   		System.out.println("Expected = true, Tested = " + testVal);
	   		if(testVal == true)
	   			System.out.println("URL TEST = PASS");
	   		else
	   			System.out.println("URL TEST = FAIL");
	   		System.out.println();
			   
	   		System.out.println("TEST URL: https://www.google.com");
	   		testVal = urlVal.isValid("https://www.google.com");
	   		System.out.println("Expected = true, Tested = " + testVal);
	   		if(testVal == true)
	   			System.out.println("URL TEST = PASS");
	   		else
	   			System.out.println("URL TEST = FAIL");
	   		System.out.println();
	   		
	   		System.out.println("TEST URL: http//www.google.com");
	   		testVal = urlVal.isValid("http//www.google.com");
	   		System.out.println("Expected = false, Tested = " + testVal);
	   		if(testVal == false)
	   			System.out.println("URL TEST = PASS");
	   		else
	   			System.out.println("URL TEST = FAIL");
	   		System.out.println();
	   		
	   		System.out.println("TEST URL: google.com");
	   		testVal = urlVal.isValid("google.com");
	   		System.out.println("Expected = false, Tested = " + testVal);
	   		if(testVal == false)
	   			System.out.println("URL TEST = PASS");
	   		else
	   			System.out.println("URL TEST = FAIL");
	   		System.out.println();
	 
	   		
	   	//URL Query Test
		urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);  
		System.out.println("Test URL Queries");
		System.out.println("____________________________");
		System.out.println();
		
   			System.out.println("TEST URL: http://www.google.com/location?name=corvallis");
   			testVal = urlVal.isValid("http://www.google.com/location?name=corvallis");
   			System.out.println("Expected = true, Tested = " + testVal);
   			if(testVal == true)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   		
   			System.out.println("TEST URL: http://www.google.com/location?name=piscataway&zip=08854");
   			testVal = urlVal.isValid("http://www.google.com/location?name=piscataway&zip=08854");
   			System.out.println("Expected = true, Tested = " + testVal);
   			if(testVal == true)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   			System.out.println("TEST URL: http://www.google.com/num?n1=1&n2=2&n3=3");
   			testVal = urlVal.isValid("http://www.google.com/num?n1=1&n2=2&n3=3");
   			System.out.println("Expected = true, Tested = " + testVal);
   			if(testVal == true)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   			System.out.println("TEST URL: http://www.google.com/location??zip=08854");
   			testVal = urlVal.isValid("http://www.google.com/location??zip=08854");
   			System.out.println("Expected = false, Tested = " + testVal);
   			if(testVal == false)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   			System.out.println("TEST URL: http://www.google.com/location?zip");
   			testVal = urlVal.isValid("http://www.google.com/location?zip");
   			System.out.println("Expected = false, Tested = " + testVal);
   			if(testVal == false)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   		//URL Path Test
   		urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);  
   		System.out.println("Test URL Path");
   		System.out.println("____________________________");
   		System.out.println();
		
   			System.out.println("TEST URL: https://www.google.com/location");
   			testVal = urlVal.isValid("https://www.google.com/location");
   			System.out.println("Expected = true, Tested = " + testVal);
   			if(testVal == true)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   			System.out.println("TEST URL: https://www.google.com/location/");
   			testVal = urlVal.isValid("https://www.google.com/location/");
   			System.out.println("Expected = true, Tested = " + testVal);
   			if(testVal == true)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   			System.out.println("TEST URL: https://www.google.com/..");
   			testVal = urlVal.isValid("https://www.google.com/..");
   			System.out.println("Expected = false, Tested = " + testVal);
   			if(testVal == false)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   		
   			System.out.println("TEST URL: https://www.google.com/../location");
   			testVal = urlVal.isValid("https://www.google.com/../location");
   			System.out.println("Expected = false, Tested = " + testVal);
   			if(testVal == false)
   				System.out.println("URL TEST = PASS");
   			else
   				System.out.println("URL TEST = FAIL");
   			System.out.println();
   			
   			
		//URL Port Test
		urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);  
		System.out.println("Test URL Ports");
		System.out.println("____________________________");
		System.out.println();
		
			System.out.println("TEST URL: https://www.google.com:5");
			testVal = urlVal.isValid("https://www.google.com:5");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:55");
			testVal = urlVal.isValid("https://www.google.com:55");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:555");
			testVal = urlVal.isValid("https://www.google.com:555");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:5555");
			testVal = urlVal.isValid("https://www.google.com:5555");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:55555");
			testVal = urlVal.isValid("https://www.google.com:55555");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:65535");
			testVal = urlVal.isValid("https://www.google.com:65535");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:0");
			testVal = urlVal.isValid("https://www.google.com:0");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: https://www.google.com:-1");
			testVal = urlVal.isValid("https://www.google.com:-1");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
		
			System.out.println("TEST URL: http//www.google.com:abc");
			testVal = urlVal.isValid("http//www.google.com:abc");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
		
			
		//URL IP Address Test
		urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);  
		System.out.println("Test URL IP Addresses");
		System.out.println("____________________________");
		System.out.println();
		
			System.out.println("TEST URL: http://190.190.190.190");
			testVal = urlVal.isValid("http://190.190.190.190");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://1.2.3.4");
			testVal = urlVal.isValid("http://1.2.3.4");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://255.255.255.255");
			testVal = urlVal.isValid("http://255.255.255.255");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://0.0.0.0");
			testVal = urlVal.isValid("http://0.0.0.0");
			System.out.println("Expected = true, Tested = " + testVal);
			if(testVal == true)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://256.256.256.256");
			testVal = urlVal.isValid("http://256.256.256.256");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
		
			System.out.println("TEST URL: http://256.1.1.1");
			testVal = urlVal.isValid("http://256.1.1.1");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://1.256.1.1");
			testVal = urlVal.isValid("http://1.256.1.1");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://1.1.256.1");
			testVal = urlVal.isValid("http://1.1.256.1");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
			
			System.out.println("TEST URL: http://1.1.1.256");
			testVal = urlVal.isValid("http://1.1.1.256");
			System.out.println("Expected = false, Tested = " + testVal);
			if(testVal == false)
				System.out.println("URL TEST = PASS");
			else
				System.out.println("URL TEST = FAIL");
			System.out.println();
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   //random test for input with IP address
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String url = "";
	   
	   int ip1 = 0;
	   int ip2 = 0;
	   int ip3 = 0;
	   int ip4 = 0;
	   int err1 = 0;
	   int err2 = 0;
	   int err3 = 0;
	   int err4 = 0;
	   int totErr = 0;
	   int por1 = 0;
	   int por2 = 0;
	   int por3 = 0;
	   int por4 = 0;
	   int g255 = 0;
	   
	   boolean shouldBe = true;
	   boolean testVal;
	   
	   Random rand = new Random();
	   
	   for(int i = 0;i<10000;i++)
	   {
		   url = "http://";
		   g255 = 0;
		   
		   ip1 = rand.nextInt(300) + 1;
		   ip2 = rand.nextInt(300) + 1;
		   ip3 = rand.nextInt(300) + 1;
		   ip4 = rand.nextInt(300) + 1;
		   
		   //verify if IP address should be valid
		   if(ip1 > 255)
		   {
			   g255++;
			   shouldBe = false;  
		   }
		   if(ip2 > 255)
		   {
			   g255++;
			   shouldBe = false;  
		   }
		   if(ip3 > 255)
		   {
			   g255++;
			   shouldBe = false;
		   }
			   
		   if(ip4 > 255)
		   {
			   g255++;
			   shouldBe = false;
		   }
		   
		   //count the number of portions which should produce error
		   if(g255 == 1)
			   por1++;
		   else if(g255 == 2)
			   por2++;
		   else if(g255 == 3)
			   por3++;
		   else if(g255 == 4)
			   por4++;

		   url += ip1 + "." + ip2 + "." + ip3 + "." + ip4;
		   testVal = urlVal.isValid(url);
		   
		   if(testVal == shouldBe)
			   continue;
		   else
		   {   
			   if(g255 == 1)
				   err1++;
			   else if(g255 == 2)
				   err2++;
			   else if(g255 == 3)
				   err3++;
			   else if(g255 == 4)
				   err4++;
			    
			   //Uncomment for Failed Input Reporting
			   //System.out.println("Failed URL: " + url);
		   }
	   }
	   
	   totErr = err1 + err2 + err3 + err4;
	   
	   System.out.println();
	   System.out.println("Random IP Address Test Results");
	   System.out.println("____________________________");
	   System.out.println("Out of 10000 Tests: Total Errors = " + totErr);
	   System.out.println("Out of " + por1 + " 1-Portion > 255 Inputs: #Errors = " + err1);
	   System.out.println("Out of " + por2 + " 2-Portion > 255 Inputs: #Errors = " + err2);
	   System.out.println("Out of " + por3 + " 3-Portion > 255 Inputs: #Errors = " + err3);
	   System.out.println("Out of " + por4 + " 4-Portion > 255 Inputs: #Errors = " + err4);
   }
   
   //random test for input with ports
   public void testAnyOtherUnitTest()
   {
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //declare URL variables
	   String url = "";
	   int portNum;
	   
	   //declare decision variables
	   boolean shouldBe, testVal;
	   int digitCount;
	   
	   //declare results variables
	   int dig1Err = 0;
	   int dig2Err = 0;
	   int dig3Err = 0;
	   int dig4Err = 0;
	   int dig5Err = 0;
	   int totErr = 0;
	   
	   //declare digit test count variables
	   int dig1 = 0;
	   int dig2 = 0;
	   int dig3 = 0;
	   int dig4 = 0;
	   int dig5 = 0;
	   
	   //declare random variables
	   int randDig;
	   
	   Random rand = new Random();
	   
	   //Random Test for Testing Port Related Failures
	   for(int i = 0; i<10000; i++)
	   {
		   url = "http://www.google.com:";
		   shouldBe = false;
		   digitCount = 0;
		   
		   		//generate random digit threshold
		   		//a random portNum will be created
		   		//is not > this # of digits
		   		randDig = rand.nextInt(5);
		   
		   		//generate pseudo random number from 0 to 70,000
		   		//with a random # of digits between 1 and 5
		   		//this will ensure some smaller digit values
		   		if(randDig == 1)
		   			portNum = rand.nextInt(9) + 1;
		   		else if(randDig == 2)
		   			portNum = rand.nextInt(99) + 1;
		   		else if(randDig == 3)
		   			portNum = rand.nextInt(999) + 1;
		   		else if(randDig == 4)
		   			portNum = rand.nextInt(9999) + 1;
		   		else 
		   			portNum = rand.nextInt(70000) + 1;
		   
		   		//get digitCount 
		   		if(portNum > 9999)
		   			digitCount = 5;
		   		else if(portNum > 999)
		   			digitCount = 4;
		   		else if(portNum > 99)
		   			digitCount = 3;
		   		else if(portNum > 9)
		   			digitCount = 2;
		   		else 
		   			digitCount = 1;
		   		
		   		//get # of test cases per digit
		   		if(digitCount == 1)
		   			dig1++;
		   		else if(digitCount == 2)
		   			dig2++;
		   		else if(digitCount == 3)
		   			dig3++;
		   		else if(digitCount == 4)
		   			dig4++;
		   		else
		   			dig5++;
		   
		   		//get shouldBe
		   		if(portNum > 65535)
		   			shouldBe = false;
		   		else
		   			shouldBe = true;
		   		
		   		//build URL and Test
		   		url += portNum;
				testVal = urlVal.isValid(url);
				
				//verify result
				if(testVal == shouldBe)
				{
					continue;
				}
				else
				{
					totErr++;
					
					if(digitCount == 1)
						dig1Err++;
					else if(digitCount == 2)
						dig2Err++;
					else if(digitCount == 3)
						dig3Err++;
					else if(digitCount == 4)
						dig4Err++;
					else 
						dig5Err++;
					
					//Uncomment to Reveal Failed URL Test Inputs
					//System.out.println("Failed URL: " + url);
				}
				
	   //end for loop
	   }
	   
	   System.out.println();
	   System.out.println("Random Port Test Results");
	   System.out.println("____________________________");
	   System.out.println("Out of 100000 Tests: Total Errors = " + totErr);
	   System.out.println("Out of " + dig1 + " 1-Digit Port Inputs: #Errors = " + dig1Err);
	   System.out.println("Out of " + dig2 + " 2-Digit Port Inputs: #Errors = " + dig2Err);
	   System.out.println("Out of " + dig3 + " 3-Digit Port Inputs: #Errors = " + dig3Err);
	   System.out.println("Out of " + dig4 + " 4-Digit Port Inputs: #Errors = " + dig4Err);
	   System.out.println("Out of " + dig5 + " 5-Digit Port Inputs: #Errors = " + dig5Err);
   }
}

/**
 * Create set of tests by taking the testUrlXXX arrays and
 * running through all possible permutations of their combinations.
 *
 * @param testObjects Used to create a url.
 */