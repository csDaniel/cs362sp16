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
	
   UrlGenerator urlGen = new UrlGenerator();
   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
   
   public UrlValidatorTest(String testName) {
	  super(testName);
   }
   
   
   public void testURLs(String type, ResultPair[] urls) {
	   
	   Boolean SUToutput;

	   for (ResultPair url : urls) {
		   GlobalVars.testcases += 1;
	       SUToutput = urlVal.isValid(url.item);
	       if (SUToutput != url.valid) {
	    	   GlobalVars.failures += 1;
	    	   if (url.valid)
	               System.out.format("%s    Good URL Failed: %s\n",  type,  url.item ); 
	    	   else 
	    		   System.out.format("%s    Bad  URL Passed: %s\n",  type,  url.item ); 
	       }
	   } 
   }
   
   public void testManual()
   {
	   testURLs("Manual Test   ", urlGen.tc.manualTests);  
   }

   public void testScheme()
   {
	   testURLs("Scheme Test   ", urlGen.tc.schemeTests);
   }
   
   public void testAuthority()
   {
       testURLs("Authority Test", urlGen.tc.authorityTests);
   }
   
   public void testPath()
   {
       testURLs("Path Test     ", urlGen.tc.pathTests);
   }
   
   public void testQuery() 
   {
       testURLs("Query Test    ", urlGen.tc.queryTests);
   }
   
   
   public void testUnit() {
	  Boolean SUToutput;
	  
	  for(int i = 0; i < urlGen.numUnitTests; i++) {
		   urlGen.unitTestUrl(i);
		   GlobalVars.testcases += 1;
	       SUToutput = urlVal.isValid(urlGen.url);
	       if (SUToutput != urlGen.valid) { 
	    	   GlobalVars.failures += 1;
	    	   if (urlGen.valid)
	    		   System.out.format("%s    Good URL Failed: %s\n",  "Unit Test     ",  urlGen.url );    
	    	   else
	    		   System.out.format("%s    Bad  URL Passed: %s\n",  "Unit Test     ",  urlGen.url );
	       }
	
	   }
   }
   
   public static void main(String[] argv) {
	    UrlValidatorTest project = new UrlValidatorTest("Final Project");
	    project.testManual();
        project.testScheme();
        project.testAuthority();    
        project.testPath();
        project.testQuery();
        project.testUnit();
	    System.out.format("Testcases: %d   Failures: %d\n", GlobalVars.testcases, GlobalVars.failures);
	}
}