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


import java.util.Objects;

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
	  // System.out.println(urlVal.isValid("http://www.amazon.com"));
	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()  //Syntax is based on this Wikipedia page: https://en.wikipedia.org/wiki/Uniform_Resource_Locator#Syntax
   {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   
	   //These are all the pieces of a url.  If a string is allowed use piece("string", true)
	   piece[] schemes = {
			   new piece("", false), 
			   new piece("http:", true),
			   new piece("https:", true),
			   new piece("ftp:", true),
			   new piece("a;lskdjf", false)
	   };
	   piece[] authorityUserNamePWs = {
			   new piece("user:password@", true),
			   new piece("", true),
			   new piece("user:password", false),
			   new piece("userpassword@", false),
			   //new piece("userpassword", false) //careful, this should bass because host becomes userpasswordhost.com
	   };
	   piece[] authorityHosts = { //TODO split this up to test all .com, .org, etc.  Also, add port IPV4 and IPV6 tests.  Need to add www tests too
			   new piece("host.com", true),
			   new piece("", false)
	   };
	   piece[] ports = {
			   new piece(":3000", true),
			   new piece("3000", false),
			   new piece("", true)
	   };
	  piece[] slashess = {
			  new piece("//", true),  //These are edited in logic below, TODO figure out what protocols allow slashes and what don't
			  new piece("", false) 
	  };
	   piece[] paths = {
			   new piece("/foo/bar", true), //allowed to begin with a slash no matter what
			   new piece("foo/bar", false),
			   new piece("", true)
			   
	   };
	   piece[] queries = {
			   new piece("?key1=value1&key2=value2", true),
			   new piece("?key1=value1;key2=value2", true),
			   new piece("", true),
			   new piece("?key1=value1key2=value2", false)
			   
	   };
	   piece[] fragments = {
			   new piece("#ThisPartOfThePage", true),
			   new piece("", true),
			   // new piece("ThisPartOfThePage", false)  //careful, this is fine if proceeded by a path "/foo/barThisPartOfThePage"
	   };
	  
	  
	   
	   for(piece scheme : schemes){
		   for (piece authorityUserNamePW : authorityUserNamePWs){
			   for (piece authorityHost : authorityHosts){
				   for(piece port : ports){
					   for (piece slashes : slashess){
						   for (piece path : paths){
							   for (piece query : queries){
								   for(piece fragment : fragments){
								  
		   


		    //TODO This is all foobar, we have to figure out how to allow/disallow "//"
	/*	   if(authorityHost.part.length() == 0){	//If the host is not declared then either slashes are not allowed, or it is an invalid url (i.e. port but no host)
			   								//May need to add what protocol is used in this logic.  According to wikipedia, some protocols (schemes) don't allow slashes and some do.  Just add protocol to 1st if(&& here)
			   								//Used length because comparing strings in Java is a pain
			   if(slashes.part.length() == 0){			//No Slashes
				   slashes.isValid = true;
			   }
			   else {									//Has slashes
				   slashes.isValid = false;
			   }
				
			   	System.out.println("I was in the loop");
			   		
		   }*/
		   
		 
		   	String url = scheme.part + slashes.part + authorityUserNamePW.part + authorityHost.part + port.part + path.part + query.part + fragment.part;
		   	boolean urlValResult = urlVal.isValid(url);
		   	boolean validURL = scheme.isValid && slashes.isValid && authorityUserNamePW.isValid && authorityHost.isValid && port.isValid && path.isValid && query.isValid && fragment.isValid;
		   	
		   	System.out.println("\n");
		   	
		   if(urlValResult == validURL){
			   System.out.println("Testing " + url + "\nPASSED");
		   }
		   else{
			   System.out.println("Testing " + url + "\nFAILED");
		   }
		   if(urlValResult){
			   System.out.println("URL Validator said this url was OK");
		   }
		   else{
			   System.out.println("URL Validator said this url was BAD");
		   }
		   }
	   }}}}}}}
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
   class piece{
	   String part;
	   boolean isValid;
	   
   public piece (String part, boolean isValid){
	   this.part = part;
	   this.isValid = isValid;
   }
   }
   

}
