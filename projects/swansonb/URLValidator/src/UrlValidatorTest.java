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

   private boolean printStatus = true;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   //Testing isValid branch on line 281
   public void testNullPartition(){
	   String testString = null;
	   boolean expectedResult = false;
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   boolean result = urlVal.isValid(testString);
	   if (printStatus) {
		   System.out.printf(
			   "PARTITION TEST: isValid(NULL) = %b,  passed:%b\n",
			   result, result == expectedResult );
	   }
	   
	   if (result != expectedResult ) fail();
   }
   
   //Testing isValid branch on line 285
   public void testASCII_PATTERNPartition(){
	   String testString = "This string will fail the ascii regex";
	   boolean expectedResult = false;
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   boolean result = urlVal.isValid(testString);
	   if (printStatus) {
		   System.out.printf(
			   "PARTITION TEST: isValid(\"%s\") = %b,  passed:%b\n",
			   testString, result, result == expectedResult );
	   }
	   
	   if (result != expectedResult ) fail();
   }
   
   //Testing isValid branch on line 291
   public void testURL_PATTERN_Partition(){

   }
   
   //Testing isValid branch on line 295
   public void testURL_SCHEME_Partition(){
	  
   }

   //Testing isValid branch on line 300
   public void testURL_AUTHORITY_Partition(){

   }

   //Testing isValid branch on line 310
   public void testURL_PATH_Partition(){

   }

   //Testing isValid branch on line 314
   public void testURL_QUERY_Partition(){

   }

   //Testing isValid branch on line 318
   public void testURL_FRAGMENT_Partition(){

   }

   //Testing isValid branch on line 324 (return true)
   public void testValidPartition(){
	   String testString = "http://www.google.com";
	   boolean expectedResult = true;
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   boolean result = urlVal.isValid(testString);
	   if (printStatus) {
		   System.out.printf(
			   "PARTITION TEST: isValid(\"%s\") = %b,  passed:%b\n",
			   testString, result, result == expectedResult );
		   System.out.flush();
	   }
	   
	   if (result != expectedResult ) fail();
   }
      

}
