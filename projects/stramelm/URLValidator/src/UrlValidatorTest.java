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
   
   public void testManual()
   {
	   // manual tests are aimed at achieving 100% code coverage (or close to it)
	   // using EclEmma 2.3.3 in Eclipse
	   
	   // valid and invalid urls tested came from here:
	   // http://formvalidation.io/validators/uri/
	   
	   // these should all be invalid
	   ManualTests.manualTest076();
	   ManualTests.manualTest075();
	   ManualTests.manualTest074();
	   ManualTests.manualTest073();
	   ManualTests.manualTest072();
	   ManualTests.manualTest071();
	   ManualTests.manualTest070();
	   ManualTests.manualTest069();
	   ManualTests.manualTest068();
	   ManualTests.manualTest067();
	   ManualTests.manualTest066();
	   ManualTests.manualTest065();
	   ManualTests.manualTest064();
	   ManualTests.manualTest063();
	   ManualTests.manualTest062();
	   ManualTests.manualTest061();
	   ManualTests.manualTest060();
	   ManualTests.manualTest059();
	   ManualTests.manualTest058();
	   ManualTests.manualTest057();
	   ManualTests.manualTest056();
	   ManualTests.manualTest055();
	   ManualTests.manualTest054();
	   ManualTests.manualTest053();
	   ManualTests.manualTest052();
	   ManualTests.manualTest051();
	   ManualTests.manualTest050();
	   ManualTests.manualTest049();
	   ManualTests.manualTest048();
	   ManualTests.manualTest047();
	   ManualTests.manualTest046();
	   ManualTests.manualTest045();
	   ManualTests.manualTest044();
	   ManualTests.manualTest043();
	   ManualTests.manualTest042();
	   ManualTests.manualTest041();
	   ManualTests.manualTest040();
	   ManualTests.manualTest039();
	   ManualTests.manualTest038();
	   
	   // these should all be valid
	   ManualTests.manualTest037();
	   ManualTests.manualTest036();
	   ManualTests.manualTest035();
	   ManualTests.manualTest034();
	   ManualTests.manualTest033();
	   ManualTests.manualTest032();
	   ManualTests.manualTest031();
	   ManualTests.manualTest030();
	   ManualTests.manualTest029();
	   ManualTests.manualTest028();
	   ManualTests.manualTest027();
	   ManualTests.manualTest026();
	   ManualTests.manualTest025();
	   ManualTests.manualTest024();
	   ManualTests.manualTest023();
	   ManualTests.manualTest022();
	   ManualTests.manualTest021();
	   ManualTests.manualTest020();
	   ManualTests.manualTest019();
	   ManualTests.manualTest018();
	   ManualTests.manualTest017();
	   ManualTests.manualTest016();
	   ManualTests.manualTest015();
	   ManualTests.manualTest014();
	   ManualTests.manualTest013();
	   ManualTests.manualTest012();
	   ManualTests.manualTest011();
	   ManualTests.manualTest010();
	   ManualTests.manualTest009();
	   ManualTests.manualTest008();
	   ManualTests.manualTest007();
	   ManualTests.manualTest006();
	   ManualTests.manualTest005();
	   ManualTests.manualTest004();
	   ManualTests.manualTest003();
	   ManualTests.manualTest002();
	   
	   // this one should be invalid
	   ManualTests.manualTest001();
   }
   
   public void testUnit()
   {
	   // unit tests are aimed at achieving determining why certain manual tests failed

	   UnitTests.unitTestLocal();
	   UnitTests.unitTestFragments();
	   UnitTests.unitTestPortNumbers();
	   UnitTests.unitTestIPAddresses();
	   
	   //UnitTests.unitTest076();
	   //UnitTests.unitTest075();

	   //UnitTests.unitTest068();
	   //UnitTests.unitTest067();
	   //UnitTests.unitTest066();
	   //UnitTests.unitTest065();

	   UnitTests.unitTest062();

	   UnitTests.unitTest034();
	   //UnitTests.unitTest033();
	   //UnitTests.unitTest032();
	   //UnitTests.unitTest031();
	   UnitTests.unitTest030();
	   UnitTests.unitTest029();
	   UnitTests.unitTest028();

	   UnitTests.unitTest026();
	   UnitTests.unitTest025();
	   UnitTests.unitTest024();

	   //UnitTests.unitTest021();
	   UnitTests.unitTest020();
	   UnitTests.unitTest019();
	   UnitTests.unitTest018();

	   //UnitTests.unitTest016();
	   //UnitTests.unitTest015();
	   //UnitTests.unitTest014();
	   //UnitTests.unitTest013();
	   UnitTests.unitTest012();
	   UnitTests.unitTest011();
	   UnitTests.unitTest010();
	   UnitTests.unitTest009();
	   UnitTests.unitTest008();
	   UnitTests.unitTest007();
	   UnitTests.unitTest006();
   }
   
}
