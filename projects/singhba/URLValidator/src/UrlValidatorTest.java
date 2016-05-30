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


import java.util.ArrayList;
import java.util.List;

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
	   System.out.println(urlVal.isValid("https://www.amazon.com/gp/yourstore/home?ie=UTF8&ref_=nav_cs_ys"));
	   System.out.println(urlVal.isValid("sftp://singhba@access.engr.oregonstate.edu"));
	   System.out.println(urlVal.isValid("sftp://access.engr.oregonstate.edu"));
	   System.out.println(urlVal.isValid("ftp://access.engr.oregonstate.edu"));
	   System.out.println(urlVal.isValid("http://www.amazon.com?q=5"));
	   System.out.println(urlVal.isValid("http://www.amazon.com?q=5&z=6"));
	   System.out.println(urlVal.isValid("https://www.google.com/webhp?q=manual"));
	   System.out.println(urlVal.isValid("https://www.goo gle.com/webhp"));
	   System.out.println(urlVal.isValid("https://www.goo#gle.com/webhp"));
	   System.out.println(urlVal.isValid("https://www.google.com/webhp/hello/world/index.php"));
	   System.out.println(urlVal.isValid("https://www.google.com/webhp/hello/world//index.php"));
	   System.out.println(urlVal.isValid("https:/www.google.com/webhp/hello/world/index.php"));
	   System.out.println(urlVal.isValid("http://10.50.158"));
	   System.out.println(urlVal.isValid("http://10.50.50.158"));
	   System.out.println(urlVal.isValid("http://10.50.50.158:3000"));
	   System.out.println(urlVal.isValid("http://www.google.com:3000"));
	   System.out.println(urlVal.isValid("http://www.-google.com"));
	   System.out.println(urlVal.isValid("http://www.google-.com"));
	   System.out.println(urlVal.isValid("http://www.goo-gle.com"));
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //Unit test to test null url
	   String url = null;
	   boolean result;
	   for(int i = 0;i<10;i++)
	   {
		   assertFalse(urlVal.isValid(url));
	   }
	   
	 //Unit test to test legal ascii 
	   List <ResultPair> ascii = new ArrayList <ResultPair>();
	   String urlPart1 = "https://go";
	   String urlPart2 = "ogle.com";
	   for (char c = ' '; c <= '~'; c++){
	       String ch = String.valueOf (c);
	       StringBuilder sb = new StringBuilder(urlPart1);  
	       sb.append(ch);
	       sb.append(urlPart2);
	       
	       //Only a - z, A - Z, 0 - 9, . and - is allowed in hostname
	       if (ch.matches(".*[a-z].*") || ch.matches(".*[A-Z].*") || ch.matches(".*[0-9].*") || ch.equals("-") || ch.equals(".")){
	    	   ascii.add (new ResultPair(sb.toString(), true));
	       }
	       
	       else{
	    	   ascii.add (new ResultPair(sb.toString(), false));
	       }
	   }
	   for (ResultPair uri : ascii) {
		   result = urlVal.isValid(uri.item);
		   if(result != uri.valid){
			   System.out.println("Test failed for url: " + uri.item);
		   }
		   assertTrue(uri.valid == result);
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
