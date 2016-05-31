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
   
   public void testManualTest8b()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:18080";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest8c()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:808";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest8d()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:8";
	  
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
   
   public void testManualTest11()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "https://www.amazon.com?site=amazon";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest12()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest13()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://ubuntu@192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest13b()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://ubuntu:ubuntu@192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest13c()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://ubuntu@www.amazon.com";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest13d()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://ubuntu:ubuntu@www.amazon.com";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   public void testManualTest14()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://ubuntu@192.168.0.1/home";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest15()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh:/ubuntu@192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest16()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://@192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest17()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://ubuntu@";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest18()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ssh://";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest19()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ftp://ubuntu@192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest20()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ftp://@192.168.0.1";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest21()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "ftp://ubuntu@";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest22()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com?site=test1&site2=test2";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest23()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:8080";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest24()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.com:fail";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest25()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.c-om";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest25b()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.combo";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(false, validatorResult);
   }
   
   public void testManualTest25c()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.aarp";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25d()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.abudhabi";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25e()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.ac";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25f()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.ad";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25g()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.mil";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25h()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.mobi";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25i()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.name";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25j()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.कॉम";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25k()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.москва";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   public void testManualTest25l()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   String testedUrl = "http://www.amazon.ಭಾರತ";
	  
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   
	   Assert.assertEquals(true, validatorResult);
   }
   
   // Input partition: protocols, i.e.: ftp, ssh, http
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // not in scheme
	   String testedUrl = "http://www.amazon.com";
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // not in scheme
	   testedUrl = "https://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // not in scheme
	   testedUrl = "ftp://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // not in scheme
	   testedUrl = "blahblahblah://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   testedUrl = "abc123://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // TODO: Check if spec allows numbers first
	   testedUrl = "123abc://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // starts with number 
	   testedUrl = "123://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no domain, no scheme
	   testedUrl = "//amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   String[] schemes = {"http","https"};
	   urlVal = new UrlValidator(schemes);
	   
	   // in scheme
	   testedUrl = "https://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // in scheme
	   testedUrl = "http://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // not in schemes
	   testedUrl = "ftp://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // not in schemes
	   testedUrl = "ssh://amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no domain
	   testedUrl = "//amazon.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
   }
   
   public void testPartitionAuthorities() 
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // correct
	   String testedUrl = "http://dave:password@dave.com";
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // unallowed char in password
	   testedUrl = "http://dave:password$@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // unallowed char in user
	   testedUrl = "http://dave$:password@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no user
	   testedUrl = "http://password@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank user
	   testedUrl = "http://:password@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no password
	   testedUrl = "http://dave@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // blank password
	   testedUrl = "http://dave:@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // host only
	   testedUrl = "http://@dave.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank host
	   testedUrl = "http://dave:password@.com";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no host extension
	   testedUrl = "http://dave:password@dave";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank host, blank extension
	   testedUrl = "http://dave:password@.";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no host
	   testedUrl = "http://dave:password";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
   }
   
   public void testPartitionHostnameAndTopLevelDomain() 
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // correct
	   String testedUrl = "http://oregonstate.edu";
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // bad characters in host
	   testedUrl = "http://!oregonstate.edu";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // bad chars in domain
	   testedUrl = "http://oregonstate.e@du";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // not long enough hostname
	   testedUrl = "http://a.edu";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // not long enough domain
	   testedUrl = "http://oregonstate.e";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank host
	   testedUrl = "http://.edu";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank domain
	   testedUrl = "http://oregonstate.";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // digits ok in host
	   testedUrl = "http://oregonstate123.edu";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // dashes okay in host
	   testedUrl = "http://oregon-state.edu";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // dashes okay in domain
	   testedUrl = "http://oregonstate.ed-u";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);

   }
   
   public void testPartitionIPAddress() 
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // correct
	   String testedUrl = "http://192.168.0.1";
	   boolean validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(true, validatorResult);
	   
	   // not enough fields
	   testedUrl = "http://192.168.0";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank field
	   testedUrl = "http://192.168..1";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // no scheme
	   testedUrl = "192.168.0.1";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // blank scheme
	   testedUrl = "//192.168.0.1";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // bad character
	   testedUrl = "http://192.168.0.L";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	   
	   // allowed char in IPv6, not IPv4
	   testedUrl = "http://192.168.0.ABC";
	   validatorResult = urlVal.isValid(testedUrl);
	   printTestResults(testedUrl, validatorResult);
	   Assert.assertEquals(false, validatorResult);
	      
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
