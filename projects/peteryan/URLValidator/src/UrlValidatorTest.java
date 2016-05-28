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

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("https://www.google.com"));
	   System.out.println(urlVal.isValid("https://www.google.com:800"));
	   System.out.println(urlVal.isValid("https://www.google.com:5000"));
	   System.out.println(urlVal.isValid("https://www.google.com:pr"));
	   System.out.println(urlVal.isValid("https://www.google.com/test"));
	   System.out.println(urlVal.isValid("https://www.google.com/test2"));
	   System.out.println(urlVal.isValid("https://www.google.com/test/test"));
	   System.out.println(urlVal.isValid("https://www.google.com/test_1"));
	   System.out.println(urlVal.isValid("https://www.google.com/afea43f4"));
	   System.out.println(urlVal.isValid("https://www.google.com//fwqrf"));
	   System.out.println(urlVal.isValid("https://www.google.com/test.fefd"));
	   System.out.println(urlVal.isValid("https://www.google.com/test/"));
	   System.out.println(urlVal.isValid("https://www.google.com/../"));
	   System.out.println(urlVal.isValid("http://www.google.com"));
	   System.out.println(urlVal.isValid("ftp://www.google.com"));
	   System.out.println(urlVal.isValid("https://google.com"));
	   System.out.println(urlVal.isValid("https://www.google.edu"));
	   System.out.println(urlVal.isValid("https://www.google"));
	   System.out.println(urlVal.isValid(""));
	   System.out.println(urlVal.isValid("www.google.com"));
	   System.out.println(urlVal.isValid("http//www.google.com"));
	   System.out.println(urlVal.isValid("https:/www.google.com"));
	   System.out.println(urlVal.isValid("https:www.google.com"));
	   System.out.println(urlVal.isValid("htp://www.google.com"));
	   System.out.println(urlVal.isValid("https://www.google.co.uk"));
	   System.out.println(urlVal.isValid("https://www.google.uk"));
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   int pass = 0;
	   int fail = 0;
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] urlScheme = {"https://", "http://", "ftp://", "h3t://", "http:/", "http//", "http:", "efe://", ""};
	   String[] urlAuthority = {"www.google.com", "google.com", "www.google.co", "www.google.co.uk", "www.google.uk", 
			   "225.225.225.225", "0.0.0.0", "225.225.225.226", "1.1.1.1", ".google.com", "google", "google.c", ""};
	   String[] urlPort = {":80", "5000", ":", ":-12", ":80.1", "80", ":80b", ""};
	   String[] urlPath = {"/test", "//test", "/test_2", "test", "/test//", "/../", "/", "/./", ""};
	   String[] urlQuery = {"?test=test", "test=test", "?", "?test", ""};
	   
	   for(int i = 0;i<10000;i++)
	   {
		   StringBuffer urlBuffer = new StringBuffer();
		   Random rand = new Random();
		   urlBuffer.append(urlScheme[rand.nextInt(urlScheme.length)]);
		   urlBuffer.append(urlAuthority[rand.nextInt(urlAuthority.length)]);
		   urlBuffer.append(urlPort[rand.nextInt(urlPort.length)]);
		   urlBuffer.append(urlPath[rand.nextInt(urlPath.length)]);
		   urlBuffer.append(urlQuery[rand.nextInt(urlQuery.length)]);
		   
		   String url = urlBuffer.toString();
		   boolean result = urlVal.isValid(url);
		   
		   if(result)
		   {
			   pass++;
		   }
		   else
		   {
			   fail++;
		   }
		   System.out.printf("(%d) %b: %s\n", i, result, url);
	   }
	   
	   System.out.printf("Pass: %d\tFail: %d\n", pass, fail);
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
   

}
