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

import java.io.FileNotFoundException;
import java.io.PrintWriter;

import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;  // print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
   }


   public void testYourFirstPartition()
   {

   }

   public void testYourSecondPartition(){

   }


   public void testIsValid() throws FileNotFoundException
   {
      boolean urlPartsAreValid = true; // a flag to keep track of bad components

      int a, b, c, d, e, f; // for-loop iterators
      int numberFailed = 0;
      int totalTested = 0;

      PrintWriter writer = new PrintWriter("unit-test-results.txt"); // to store our output in a file for analysis
      UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); // instantiate a URL validator

     /*
      The following block builds every combination of every component and tests the final result versus
      if we expected a fail (based on any of the components being bad)
     */
        for (a = 0; a < testScheme.length; a++){
           if (testScheme[a].valid == false) {
             urlPartsAreValid = false; // a single invalid part will invalidate the url
          }
           for (b = 0; b < testAuth.length; b++){
             // from now on the urlPartsAreValid flag only needs to be set false if it hasn't already
             if (testAuth[b].valid == false && urlPartsAreValid == true) {
               urlPartsAreValid = false;
             }
             for (c = 0; c < testPort.length; c++){
                if (testPort[c].valid == false && urlPartsAreValid == true) {
                 urlPartsAreValid = false;
              }
                for (d = 0; d < testPath.length; d++){
                   if (testPath[d].valid == false && urlPartsAreValid == true) {
                    urlPartsAreValid = false;
                 }
                   for (e = 0; e < testOptions.length; e++){
                      if (testOptions[e].valid == false && urlPartsAreValid == true) {
                       urlPartsAreValid = false;
                    }
                      for (f = 0; f < testQuery.length; f++){
                        // note there are no invalid queries

                        // build the URL by concatenating each component into one big string
                        String url = testScheme[a].item + testAuth[b].item + testPort[c].item + testPath[d].item + testOptions[e].item + testQuery[f].item;
                        // validate the final string and check if the result matches what we think it should be (based on the parts)
                        boolean urlIsValid = validator.isValid(url);
                        if ((urlIsValid == true && urlPartsAreValid == false) || (urlIsValid == false && urlPartsAreValid == true)) {
                           numberFailed++;
                           System.out.println("FAILED: " + url);
                           writer.println("FAILURE #" + numberFailed + ": " + url + "  [ returned " + urlIsValid + ", expected " + urlPartsAreValid + " ]");
                           System.out.println("EXPECTED: " + urlPartsAreValid);
                           System.out.println("RESULT: " + urlIsValid + "\n\n");
                        }
                        totalTested++;
                     }
                   }
                }
             }
          }
        }
        System.out.println("TOTAL TEST CASES: " + totalTested);
        System.out.println("TOTAL TEST FAILS: " + numberFailed);
        writer.println("TOTAL TEST CASES: " + totalTested);
        writer.println("TOTAL TEST FAILS: " + numberFailed);
        writer.close();
     } // end test is valid

   public void testAnyOtherUnitTest()
   {

   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */

    static ResultPair[] testScheme = { new ResultPair("http://", true),
                                   new ResultPair("ftp://", true),
                                   new ResultPair("h3t://", true),
                                   new ResultPair("3ht://", false),
                                   new ResultPair("http:/", false),
                                   new ResultPair("http:", false),
                                   new ResultPair("http/", false),
                                   new ResultPair("://", false),
                                   new ResultPair("", true) };

    static ResultPair[] testAuth = { new ResultPair("www.google.com", true),
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
                                      new ResultPair("", false) };

    static ResultPair[] testPort = { new ResultPair(":80", true),
                                 new ResultPair(":65535", true),
                                 new ResultPair(":0", true),
                                 new ResultPair("", true),
                                 new ResultPair(":-1", false),
                                 new ResultPair(":65636", true),
                                 new ResultPair(":65a", false) };

    static ResultPair[] testPath = { new ResultPair("/test1", true),
                              new ResultPair("/t123", true),
                              new ResultPair("/$23", true),
                              new ResultPair("/..", false),
                              new ResultPair("/../", false),
                              new ResultPair("/test1/", true),
                              new ResultPair("", true),
                              new ResultPair("/test1/file", true),
                              new ResultPair("/..//file", false),
                              new ResultPair("/test1//file", false)};

    //Test allow2slash, noFragment
    static ResultPair[] testOptions = { new ResultPair("/test1", true),
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
                                        new ResultPair("/#/file", false) };

   static ResultPair[] testQuery = { new ResultPair("?action=view", true),
                                 new ResultPair("?action=edit&mode=up", true),
                                 new ResultPair("", true) };

}
