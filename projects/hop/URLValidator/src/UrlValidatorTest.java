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

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("http://www.amazon.com expected = true, actual = " + urlVal.isValid("http://www.amazon.com"));	   			
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   System.out.println("ftp://access.engr.oregonstate.edu expected = true, actual = " + urlVal.isValid("ftp://access.engr.oregonstate.edu"));
	   assertTrue(urlVal.isValid("ftp://access.engr.oregonstate.edu"));
	   System.out.println("http://12345.com expected = true, actual = " + urlVal.isValid("http://12345.com"));					
	   assertTrue(urlVal.isValid("http://12345.com"));
	   System.out.println("asdf expected = false, actual = " + urlVal.isValid("asdf"));								
	   assertTrue(!urlVal.isValid("asdf"));
	   System.out.println("http://1234 expected = false, actual = " + urlVal.isValid("http://1234"));						
	   assertTrue(!urlVal.isValid("http://1234"));
	   System.out.println("http://books expected = false, actual = " + urlVal.isValid("http://books"));						
	   assertTrue(!urlVal.isValid("http://books"));
	   System.out.println("http://127.0.0.1 expected = true, actual = " + urlVal.isValid("http://127.0.0.1"));					
	   assertTrue(urlVal.isValid("http://127.0.0.1"));
	   System.out.println("http://www.google.com:80 expected = true, actual = " + urlVal.isValid("http://www.google.com:80"));			
	   assertTrue(urlVal.isValid("http://www.google.com:80"));
	   System.out.println("http://127.0.0.1:8080 expected = true, actual = " + urlVal.isValid("http://127.0.0.1:8080/"));			// returns false, NOT expected
	   //assertTrue(urlVal.isValid("http://127.0.0.1:8080")); //assertion fails, see bug report #1 on Google Doc.
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
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
   
   public static void main(String[] argv){
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   fct.testManualTest();
	   fct.testYourFirstPartition();
	   fct.testYourSecondPartition();
	   fct.testIsValid();
	   fct.testAnyOtherUnitTest();
   }
   

}
