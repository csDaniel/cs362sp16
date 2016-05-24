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

import org.junit.Assert;
import junit.framework.TestCase;

/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = true;
   private boolean printIndex = true;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   private void printTestResults(String theUrl, boolean theResult) {
	   if(printIndex){
		   System.out.println(theUrl);
	   }
	   if(printStatus) {
		   System.out.println(theResult);
	   }   
   }
   
   public void testManualTest1()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest2()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "}}}://www.amazon.com";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest3()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://}}}.com";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest4()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.}}}";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest5()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com/amazon";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest6()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com/}}}";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest7()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://255.255.255.255";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest8()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:8080";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest9()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:}}}";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest10()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?site=amazon";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest10b()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?a=a";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest10c()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?1=1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest10d()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?a";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest10e()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest10f()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?}}}=}}}";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
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
   

}
