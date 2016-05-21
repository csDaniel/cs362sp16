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
   
   //first three are true
   private String[] schemes = {"http://", "https://", "ftp://", "htt://", "htts://", "http:", "///", "https//"};
   private String[] authorities = {"auth1", "auth2", "auth3", "auth4", "auth5", "auth6", "auth7", "auth8"};
   private String[] ports = {"ports1", "ports2", "ports3", "ports4", "ports5", "ports6", "ports7", "ports8"};
   private String[] paths = {"paths1", "paths2", "paths3", "paths4", "paths5", "paths6", "paths7", "paths8"};
   private String[] queries = {"quers1", "quers2", "quers3", "quers4", "quers5", "quers6", "quers7", "quers8"};
   
   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("htts://www.google.com"));
	     
   }
   
   public void testIsValid()
   {   
	   Boolean expectedValue = true; //true
	   
	   for(int i = 0; i<schemes.length; i++){   
		   for(int j = 0; j<authorities.length; j++){
			   for(int k = 0; k<ports.length; k++){
				   	for(int l = 0; l<paths.length; l++){
				   		for(int m = 0; m<queries.length; m++){
						   String URL = new String("");
						   expectedValue = true;
						   changeFlag(expectedValue, i);
						   changeFlag(expectedValue, j);
						   changeFlag(expectedValue, k);
						   changeFlag(expectedValue, l);
						   changeFlag(expectedValue, m);
						   URL = URL + schemes[i] + authorities[j] + ports[k] + paths[l] + queries[m];

						   collector(URL, expectedValue);
					   }
				   }
			   }
		   }
	   }
   }
   
   //change flag to false
   //if its in the first half of the array, it's "true" 
   public void changeFlag(Boolean flag, int place){
	   if(place>3){
		   flag = false;
	   }
   }
   
   public void collector(String URL, Boolean expectedValue){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("expectedValue: " + expectedValue + " URL: " + URL);
	   System.out.println(" Actual Result: " + urlVal.isValid(URL));
	   
	   if(expectedValue == true){
		   assertTrue(URL + " should be valid",
	                urlVal.isValid(URL));
	   } else {
	       assertFalse(URL + " should not be valid",
	                urlVal.isValid(URL));   
	   }	   
   }
}

