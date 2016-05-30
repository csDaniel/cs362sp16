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

import junit.framework.Assert;
import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {
	
	
	protected void setUp() throws Exception {
		super.setUp();
	}
	
	private boolean printStatus = false;
	private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

	public UrlValidatorTest(String testName) {
		super(testName);
	}

   
   
	@SuppressWarnings("deprecation")
	public void testManualTest() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   boolean valid;
	   valid = urlVal.isValid("http://www.amazon.com");
	   Assert.assertEquals(valid, true);
	   valid = urlVal.isValid("https://www.google.com");
	   Assert.assertEquals(valid, true);
	   valid = urlVal.isValid("https://///www.google.com");
	   Assert.assertEquals(valid, true);
	   valid = urlVal.isValid("https://oregonstate.instructure.com/courses/1583026/pages/course-project-+-final-project?module_item_id=16758352");
	   Assert.assertEquals(valid, true);
	}
   
   
	public void testYourFirstPartition() {
	   
	}
   
	public void testYourSecondPartition() {
	   
	}
   
   
	public void testIsValid() {
		for(int i = 0;i<10000;i++) {
		   
		}
	}
   
	public void testAnyOtherUnitTest() {
	   
	}
   /**
* Create set of tests by taking the testUrlXXX arrays and
* running through all possible permutations of their combinations.
*
* @param testObjects Used to create a url.
*/
   

}
