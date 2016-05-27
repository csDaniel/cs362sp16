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

import org.junit.Test;

import static org.junit.Assert.*;





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

   
   
   public void testManualTest()
   {

   }
   
   
   public void testYourFirstPartition()
   {   
	   //schemes
	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("Test Schemes:");

	   //Allow all schemes on
	   //true schemes
	   //http
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://amazon.com"));
	   assertTrue(urlValidator.isValid("http://amazon.com"));

	   //https
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("https://amazon.com"));
	   assertTrue(urlValidator.isValid("https://amazon.com"));

	   //ftp
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("ftp://amazon.com"));
	   assertTrue(urlValidator.isValid("ftp://amazon.com"));

	   //false schemes
	   // ://
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("://amazon.com"));
	   assertFalse(urlValidator.isValid("://amazon.com"));

	   //3ht
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("3ht://amazon.com"));
	   assertFalse(urlValidator.isValid("3ht://amazon.com"));

	   //no scheme
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("//amazon.com"));
	   assertFalse(urlValidator.isValid("//amazon.com"));

	   //Allow all schemes off
	   String[] schemes = {"http", "https"};
	   urlValidator = new UrlValidator(schemes);
	   //true scheme
	   //in scheme
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("https://amazon.com"));
	   assertTrue(urlValidator.isValid("https://amazon.com"));

	   //false scheme
	   //not in scheme
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("ftp://amazon.com"));
	   assertFalse(urlValidator.isValid("ftp://amazon.com"));
   }
   
   public void testYourSecondPartition(){
	   //authorities
	   System.out.println("Test Authority:");

	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //true authorities
	   //hostnames
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com"));
	   assertTrue(urlValidator.isValid("http://www.google.com"));

	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://go.com"));
	   assertTrue(urlValidator.isValid("http://go.com"));

	   //IP address
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://0.0.0.0"));
	   assertTrue(urlValidator.isValid("http://0.0.0.0"));


	   //false authorities
	   //hostnames
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://go.a"));
	   assertFalse(urlValidator.isValid("http://go.a"));

	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://go.1aa"));
	   assertFalse(urlValidator.isValid("http://go.1aa"));

	   //IP address
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://1.2.3.4.5"));
	   assertFalse(urlValidator.isValid("http://1.2.3.4.5"));

	   //empty authority
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://test1"));
	   assertFalse(urlValidator.isValid("http://test1"));

	   //port
	   //true ports
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com:80"));
	   assertTrue(urlValidator.isValid("http://www.google.com:80"));

	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com:0"));
	   assertTrue(urlValidator.isValid("http://www.google.com:0"));

	   //false ports
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://www.google.com:-1"));
	   assertFalse(urlValidator.isValid("http://www.google.com:-1"));

	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://www.google.com:80aa"));
	   assertFalse(urlValidator.isValid("http://www.google.com:80aa"));
   }

   public void testYourThirdPartition(){
	   //path
	   System.out.println("Test Path:");

	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //true paths
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com/test1"));
	   assertTrue(urlValidator.isValid("http://www.google.com/test1"));

	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://google.com/t123"));
	   assertTrue(urlValidator.isValid("http://google.com/t123"));

	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://google.com/test/file"));
	   assertTrue(urlValidator.isValid("http://google.com/test/file"));

	   //false paths
	   //..
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://google.com/../"));
	   assertFalse(urlValidator.isValid("http://google.com/../"));

	   //two slashes
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://google.com/test1//file"));
	   assertFalse(urlValidator.isValid("http://google.com/test1//file"));

	   //Allow two slashes on
	   urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_2_SLASHES);

	   //true
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://google.com/test1//file"));
	   assertTrue(urlValidator.isValid("http://google.com/test1//file"));
   }

   public void testYourFourthPartition(){
	   //query
	   System.out.println("Test Query:");

	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //true queries
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com?action=view"));
	   assertTrue(urlValidator.isValid("http://www.google.com?action=view"));

	   //Two words w/ + sign
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com?action=view+one"));
	   assertTrue(urlValidator.isValid("http://www.google.com?action=view+one"));

	   //false queries
	   //Two words w/ space
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://www.google.com?action=view one"));
	   assertFalse(urlValidator.isValid("http://www.google.com?action=view one"));

   }

   public void testYourFifthPartition(){
	   //fragment
	   System.out.println("Test Fragment:");

	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //true fragment
	   System.out.println("Expcted: true   Actual: " + urlValidator.isValid("http://www.google.com#print"));
	   assertTrue(urlValidator.isValid("http://www.google.com#print"));


	   urlValidator = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
	   //fragments not enabled
	   System.out.println("Expcted: false   Actual: " + urlValidator.isValid("http://www.google.com#print"));
	   assertFalse(urlValidator.isValid("http://www.google.com#print"));
   }
   
   
   public void testIsValid()
   {
	   // Set up random number generator
	   Random rand = new Random();
	   
	   // Create an object with all 6 parts
	   Object[] randUrlParts = {randUrlScheme, randUrlAuthority, randUrlPort, randPath, randUrlPathOptions, randUrlQuery};
	   String[] randUrlTypes = {"Scheme", "Authority", "Port", "Path", "Path Options", "Query"};
	   
	   // Declare a url validator object
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   

	   // Create a new matrix to store the failure frequencies of each part
	   int [][] failures = new int [randUrlParts.length][];
	   for (int i = 0; i < randUrlParts.length; i++){
		   ResultPair[] randPart = (ResultPair[]) randUrlParts[i];
		   failures[i] = new int [randPart.length];		
	   }
	   
	   System.out.println("---------------------------------------------------------------------");
	   System.out.println("Random Tester");
	   System.out.println("---------------------------------------------------------------------");
	   
	   // Use random testing to pick the points
	   int wrongCount = 0;
	   int testCount = 10000;
	   for(int i = 0;i< testCount; i++)
	   {
		   // Create a new empty string to store the new urls		   
		   StringBuffer randString = new StringBuffer();
		   boolean randValid = true;
		   
		   // Create a new integer array to store the indices
		   int [] indices = new int[randUrlParts.length];
		   
		   
		   // For each part of the url
		   for (int j = 0; j < randUrlParts.length; j++){
			   
			   //Extract the ResultPair array
			   ResultPair[] part = (ResultPair[]) randUrlParts[j];
			   
			   // Pick random variables from each one
			   int index = rand.nextInt(part.length);
			   indices[j] = index;
			   
			   // Append that random item and evaluate the validity
			   randString.append(part[index].item);
			   randValid = randValid & part[index].valid;
		   }
		   
		   // Compare expected to actual result
		   boolean expectedResult = randValid;
		   String testThis = randString.toString();
		   boolean validResult = urlVal.isValid(testThis);
		   
		   // If unexpected, increment failure count and output results
		   if (validResult != randValid){
			   wrongCount++;
			   
			   /*
			   System.out.println(randString);
			   System.out.println("Expected = " + randValid);
			   System.out.println("Actual = " + validResult);
			   System.out.println(" ");
			   */
			   
			   // Update the failure report
			   for (int j = 0; j < randUrlParts.length; j++){
				   int failureIndex = indices[j];
				   failures[j][failureIndex]++;
			   }
		   }
	   }
	   
	   // Print out how many were wrong
	   System.out.println(" ");
	   System.out.println("Wrong results: " + wrongCount + " out of " + testCount);
	   System.out.println(" ");
	   
	   // Print out the failure rate
	   for (int i = 0; i < randUrlParts.length; i++){
		   
		   //Extract the ResultPair array
		   ResultPair[] failurePart = (ResultPair[]) randUrlParts[i];
		   String failureType = randUrlTypes[i];
		   
		   // Print the results of the array
		   System.out.println("------" + failureType + "------");
		   for (int j = 0; j < failurePart.length; j++){
			   System.out.println(String.format("%-30s",failurePart[j].item) + failures[i][j]);
		   }
		   System.out.println(" ");
	   }
	   
	   System.out.println("---------------------------------------------------------------------");
	   System.out.println("Complete Tester");
	   System.out.println("---------------------------------------------------------------------");
	   
	   // Testing only 5 parts of the url
	   Object[] iterUrlParts = {randUrlScheme, randUrlAuthority, randUrlPort, randPath, randUrlQuery};
	   String[] iterUrlTypes = {"Scheme", "Authority", "Port", "Path", "Query"};
	   
	   // Create a second matrix to store the failure frequencies of each part
	   int [][] loopFailures = new int [iterUrlParts.length][];
	   for (int i = 0; i < iterUrlParts.length; i++){
		   ResultPair[] completePart = (ResultPair[]) iterUrlParts[i];
		   loopFailures[i] = new int [completePart.length];		
	   }
	   
	   // Reset the counter
	   wrongCount = 0;
	   testCount = 0;
	   
	   // Go through each and every scheme
	   for (int i = 0; i < randUrlScheme.length; i++){
		   for (int j = 0; j < randUrlAuthority.length; j++){
			   for (int k = 0; k < randUrlPort.length; k++){
				   for (int l = 0; l < randPath.length; l++){
					   for (int m = 0; m < randUrlQuery.length; m++){
						   
						   // Increment loop count
						   testCount++;
						   
						   // Declare the buffer to hold the string
						   StringBuffer loopBuffer = new StringBuffer();
						   boolean loopValid = true;
						   
						   // Construct the loop buffer
						   loopBuffer.append(randUrlScheme[i].item);
						   loopBuffer.append(randUrlAuthority[j].item);
						   loopBuffer.append(randUrlPort[k].item);
						   loopBuffer.append(randPath[l].item);
						   loopBuffer.append(randUrlQuery[m].item);
						   
						   // Construct the expected value
						   loopValid = loopValid & randUrlScheme[i].valid & randUrlAuthority[j].valid & randUrlPort[k].valid & randPath[l].valid & randUrlQuery[m].valid;
						   
						   // Test the looped string
						   String loopString = loopBuffer.toString();
						   boolean loopResult = urlVal.isValid(loopString);
						   
						   // If the results are unexpected
						   if (loopValid != loopResult){
							   
							   // Store the result
							   wrongCount++;
							   loopFailures[0][i]++;
							   loopFailures[1][j]++;
							   loopFailures[2][k]++;
							   loopFailures[3][l]++;
							   loopFailures[4][m]++;
							   
							   // Print the result
							   /*
							   String resultString;
							   System.out.println(String.format("%-60s", resultString = loopString) + "Expected: " + loopValid + "\tActual: " + urlVal.isValid(loopString));
							   */   
						   }   
					   }
				   }
			   }
		   }
	   }
	   
	   // Print out how many were wrong
	   System.out.println(" ");
	   System.out.println("Wrong results: " + wrongCount + " out of " + testCount);
	   System.out.println(" ");
	   
	   // Print out the failure rate
	   for (int i = 0; i < iterUrlParts.length; i++){
		   
		   //Extract the ResultPair array
		   ResultPair[] iterFailurePart = (ResultPair[]) iterUrlParts[i];
		   String iterFailureType = iterUrlTypes[i];
		   
		   // Print the results of the array
		   System.out.println("------" + iterFailureType + "------");
		   for (int j = 0; j < iterFailurePart.length; j++){
			   System.out.println(String.format("%-30s",iterFailurePart[j].item) + loopFailures[i][j]);
		   }
		   System.out.println(" ");
	   }
	   

	   System.out.println("---------------------------------------------------------------------");
	   System.out.println("Part Tester");
	   System.out.println("---------------------------------------------------------------------");
	   
	   // Go through each element 
	   for (int i = 0; i < iterUrlParts.length; i++){
		   
		   // Go through each part
		   ResultPair[] iterPart = (ResultPair[]) iterUrlParts[i];
		   String iterFailureType = iterUrlTypes[i];
		   System.out.println("------" + iterFailureType + "------");
		   
		   for (int j = 0; j < iterPart.length; j++){
			   
			   // Initialize with all true elements
			   String[] iterString = {"http://", "www.google.com", ":80", "/test1", ""};
			   //String[] iterString = {"3ht://", "256.256.256.256", ":-1", "/test1", "?action=view"};
			   
			   // Pick the random item and turn into a StringBuffer
			   iterString[i] = iterPart[j].item;
			   boolean insideValid = iterPart[j].valid;
			  
			   // Condense into a single string
			   StringBuffer insideBuffer = new StringBuffer();
			   for (int k = 0; k < iterString.length; k++){
				   insideBuffer.append(iterString[k]);
			   }

			   // Test the looped string
			   String insideString = insideBuffer.toString();
			   boolean insideResult = urlVal.isValid(insideString);
			   
			   // Print out unexpected results
			   if (insideResult != insideValid){
				   String insidePrint;
				   System.out.println(String.format("%-60s", insidePrint = insideString) + "Expected: " + insideValid + "\tActual: " + insideResult);
			   }   
		   }
		   System.out.println(" ");
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   ResultPair[] randUrlScheme = 
	   {new ResultPair("http://", true),
       new ResultPair("ftp://", true),
       new ResultPair("h3t://", true),
       new ResultPair("3ht://", false),
       new ResultPair("http:/", false),
       new ResultPair("http:", false),
       new ResultPair("http/", false),
       new ResultPair("h://", false),
       new ResultPair("://", false),
       new ResultPair("", false)};   

   ResultPair[] randUrlAuthority = 
	   {new ResultPair("www.google.com", true),
       new ResultPair("go.com", true),
       new ResultPair("go.au", true),
       new ResultPair("0.0.0.0", true),
       new ResultPair("255.255.255.255", true),
       new ResultPair("256.256.256.256", false),
       new ResultPair("255.com", true),
       new ResultPair("1.2.3.4.5", false),
       new ResultPair("1.2.3.4.", false),
       new ResultPair("1.2.3", false),
       new ResultPair(".1.2.3.4", false),
       new ResultPair("go.a", false),
       new ResultPair("go.a1a", false),
       new ResultPair("go.cc", true),
       new ResultPair("go.1aa", false),
       new ResultPair("aaa.", false),
       new ResultPair(".aaa", false),
       new ResultPair("aaa", false),
       new ResultPair("", false)
	};
	ResultPair[] randUrlPort = {new ResultPair(":80", true),
	      new ResultPair(":65535", true),
	      new ResultPair(":0", true),
	      new ResultPair("", true),
	      new ResultPair(":-1", false),
	      new ResultPair(":65636", true),
	      new ResultPair(":65a", false)
	};
	ResultPair[] randPath = {new ResultPair("/test1", true),
	   new ResultPair("/t123", true),
	   new ResultPair("/$23", true),
	   new ResultPair("/..", false),
	   new ResultPair("/../", false),
	   new ResultPair("/test1/", true),
	   new ResultPair("", true),
	   new ResultPair("/test1/file", true),
	   new ResultPair("/..//file", false),
	   new ResultPair("/test1//file", false)
	};
	
	//Test allow2slash, noFragment
	ResultPair[] randUrlPathOptions = 
		{new ResultPair("/test1", true),
         new ResultPair("/t123", true),
         new ResultPair("/$23", true),
         new ResultPair("/..", false),
         new ResultPair("/../", false),
         new ResultPair("/test1/", true),
         new ResultPair("/#", false),
         new ResultPair("", true),
         new ResultPair("/test1/file", true),
         new ResultPair("/t123/file", true),
         new ResultPair("/$23/file", true),
         new ResultPair("/../file", false),
         new ResultPair("/..//file", false),
         new ResultPair("/test1//file", true),
         new ResultPair("/#/file", false)
	};
	
	ResultPair[] randUrlQuery = 
		{new ResultPair("?action=view", true),
       new ResultPair("?action=edit&mode=up", true),
       new ResultPair("?'", false),
       new ResultPair("", true)
	};
}
