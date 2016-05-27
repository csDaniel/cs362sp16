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


/**
*
*
*
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
     // expect true
     System.out.println("Expect true for three tests:");
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
     assertTrue(urlVal.isValid("http://www.amazon.com"));
     System.out.println(urlVal.isValid("https://inbox.gmail.com"));
     assertTrue(urlVal.isValid("https://inbox.gmail.com"));
     System.out.println(urlVal.isValid("https://inbox.gmail.com?foo=bar"));
     //assertTrue(urlVal.isValid("https://inbox.gmail.com?foo=bar"));
     // expect false
     System.out.println("Expect false for three tests:");
     System.out.println(urlVal.isValid("https://inbox.gmail.com?foo bar"));
     assertFalse(urlVal.isValid("https://inbox.gmail.com?foo bar"));
     System.out.println(urlVal.isValid("https://inbox.gmail.com>"));
     assertFalse(urlVal.isValid("https://inbox.gmail.com>"));
     System.out.println(urlVal.isValid("derp://40404:9000000"));
     assertFalse(urlVal.isValid("derp://40404:9000000"));


     System.out.println(testUrlScheme.length);

   }
   
   
   public void testYourFirstPartition()
   {
	   // so we should partition the inputs to hit most of the functions within the
     // UrlValidator class. For this partition, we're going to do "valid" inputs.
     // We have to break this up so that we can hit as many different functions
     // within the class but want to make our inputs demonstrate good path coverage

      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      System.out.println("All of the following test cases should return true:");
      System.out.println("Test Schemes:");

      System.out.println(urlVal.isValid("http://www.amazon.com"));
      assertTrue(urlVal.isValid("http://www.amazon.com"));
      System.out.println(urlVal.isValid("https://www.google.com"));
      assertTrue(urlVal.isValid("https://www.google.com"));
      System.out.println(urlVal.isValid("ftp://myftpsite.com"));
      assertTrue(urlVal.isValid("ftp://myftpsite.com"));
      System.out.println("Test Authority:");
      System.out.println(urlVal.isValid("http://www.amazon.com:80"));
      assertTrue(urlVal.isValid("http://www.amazon.com:80"));
      System.out.println(urlVal.isValid("http://192.168.1.1:9000"));
      assertTrue(urlVal.isValid("http://192.168.1.1:9000"));
      System.out.println(urlVal.isValid("http://www.amazon.com:55555"));
      assertTrue(urlVal.isValid("http://www.amazon.com:55555"));
      System.out.println(urlVal.isValid("file://mypiratedtextbook.pdf"));
      assertTrue(urlVal.isValid("file:///mypiratedtextbook.pdf"));
      System.out.println("Test Path:");
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift"));
      assertTrue(urlVal.isValid("http://www.amazon.com/redeemgift"));
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift/buylotsofstuff"));
      assertTrue(urlVal.isValid("http://www.amazon.com/redeemgift/buylotsofstuff"));
      System.out.println("Test Query:");
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift?order=now"));
      assertTrue(urlVal.isValid("http://www.amazon.com/redeemgift?order=now"));
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift?order=now&makeit=snappy"));
      assertTrue(urlVal.isValid("http://www.amazon.com/redeemgift?order=now&makeit=snappy"));
      System.out.println("Test Fragment:");
      System.out.println(urlVal.isValid("https://en.wikipedia.org/wiki/Illegal_number#References"));
      assertTrue(urlVal.isValid("https://en.wikipedia.org/wiki/Illegal_number#References"));

   }
   
   public void testYourSecondPartition(){
	   // for the second partition, we would like to hit the same functions as before, but
     // this time we're going to use what we know to be invalid inputs, so we know that 
     // bad input is checked. We want to continue to use known good inputs so the individual
     // functions that test each component catch the single problematic piece and 
     // correctly mark the URL as invalid

      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      System.out.println("All of the following test cases should return false:");
      System.out.println("Test Schemes:");
      System.out.println(urlVal.isValid("http:///www.amazon.com"));
      assertFalse(urlVal.isValid("http:///www.amazon.com"));
      System.out.println(urlVal.isValid("https//www.google.com"));
      assertFalse(urlVal.isValid("https//www.google.com"));
      System.out.println(urlVal.isValid("myftpsite.com"));
      assertFalse(urlVal.isValid("myftpsite.com"));
      System.out.println("Test Authority:");
      System.out.println(urlVal.isValid("http://www.amazon.com80"));
      assertFalse(urlVal.isValid("http://www.amazon.com80"));
      System.out.println(urlVal.isValid("http://192.168.1.1.1:9000"));
      assertFalse(urlVal.isValid("http://192.168.1.1.1:9000"));
      System.out.println(urlVal.isValid("http://www.amazon.com:8888888"));
      assertFalse(urlVal.isValid("http://www.amazon.com:8888888"));
      System.out.println(urlVal.isValid("http:// this is not valid"));
      assertFalse(urlVal.isValid("http:// this is not valid"));
      System.out.println("Test Path:");
      System.out.println(urlVal.isValid("http://www.amazon.com/<redeemgift"));
      assertFalse(urlVal.isValid("http://www.amazon.com/<redeemgift"));
      System.out.println(urlVal.isValid("http:////redeemgift"));
      assertFalse(urlVal.isValid("http:////redeemgift"));
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift/buylotsofstu>ff"));
      assertFalse(urlVal.isValid("http://www.amazon.com/redeemgift/buylotsofstu>ff"));
      System.out.println(urlVal.isValid("http://www.amazon.com/redee:gift/buylotsofstu>ff"));
      assertFalse(urlVal.isValid("http://www.amazon.com/redee:gift/buylotsofstu>ff"));
      System.out.println("Test Query:");
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift?order now"));
      assertFalse(urlVal.isValid("http://www.amazon.com/redeemgift?order now"));
      System.out.println(urlVal.isValid("http://www.amazon.com/redeemgift?order=now&#makeit=snappy"));
      assertFalse(urlVal.isValid("http://www.amazon.com/redeemgift?order=now&#makeit=snappy"));

   }
   
   



   public void testIsValid()
   {
    // initialize the validator object
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

     int scheme_length = testUrlScheme.length - 1;
     int authority_length = testUrlAuthority.length - 1;
     int port_length = testUrlPort.length - 1;
     int path_length = testPath.length - 1;
     int query_length = testUrlQuery.length - 1;

     // iterate in a similar manner to the demonstration shown
	   for(int i = 0;i<20000;i++){
      StringBuffer testBuffer = new StringBuffer();
      boolean expected = true;
      for(int index = 0; index < testPartsIndex.length; ++index){
        int index_val = testPartsIndex[index];
        ResultPair [] part = (ResultPair[]) testUrlParts[index];
		    testBuffer.append(part[index_val].item);
        expected &= part[index_val].valid;
	    }
      String url = testBuffer.toString();
      boolean result = urlVal.isValid(url);

      //assertEquals(url, expected, result);
      if(result != expected){
        System.out.printf("Error case found: %s, expected %b, got %b\n", url, expected, result);
      }

      if (testPartsIndex[4] == query_length){
        testPartsIndex[4] = 0;
        if (testPartsIndex[3] == path_length){
          testPartsIndex[3] = 0;
          if (testPartsIndex[2] == port_length){
            testPartsIndex[2] = 0;
            if(testPartsIndex[1] == authority_length){
              testPartsIndex[1] = 0;
              if(testPartsIndex[0] == scheme_length){
                return;
              }else{
                testPartsIndex[0]++;
              }
            }else{
              testPartsIndex[1]++;
            }
          }else{
            testPartsIndex[2]++;
          }
        }else{
          testPartsIndex[3]++;
        }
      }else{
        testPartsIndex[4]++;
      }

    }//endfor

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
   


  ResultPair[] testUrlScheme = {
   new ResultPair("http://", true),
   new ResultPair("ftp://", true),
   new ResultPair("h3t://", true),
   new ResultPair("3ht://", false),
   new ResultPair("http:/", false),
   new ResultPair("http:", false),
   new ResultPair("http/", false),
   new ResultPair("://", false),
   new ResultPair("", true)
  };

  ResultPair[] testUrlAuthority = {
    new ResultPair("www.google.com", true),
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

  ResultPair[] testUrlPort = {
   new ResultPair(":80", true),
   new ResultPair(":65535", true),
   new ResultPair(":0", true),
   new ResultPair("", true),
   new ResultPair(":-1", false),
   new ResultPair(":65636", true),
   new ResultPair(":65a", false)
   };

   ResultPair[] testPath = {
    new ResultPair("/test1", true),
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

   ResultPair[] testUrlQuery = {
    new ResultPair("?action=view", true),
    new ResultPair("?action=edit&mode=up", true),
    new ResultPair("", true)
   };

   Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
   int[] testPartsIndex = {0, 0, 0, 0, 0};



}
