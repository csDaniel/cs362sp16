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
import java.util.regex.Pattern;

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
   
   //testing invalid parts of a url
   public void testYourFirstPartition()
   {
	   //first partition includes many not valid parts and full urls
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //test if null is a valid url
	   boolean result = urlVal.isValid(null);
	   System.out.println("Testing if null is valid url =  " + result);
	   System.out.println("\n");	   
	  
	   //fails url pattren mactcher
	   result = urlVal.isValid("http://www.goooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo-ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooogle.com");
	   System.out.println("Testing if http://www.goooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo-ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooogle.com is a valid authority =  " + result);
	   System.out.println("\n");	   
	   
	   // to long of label
	   result = urlVal.isValid("www.gooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooogle.com");
	   System.out.println("Testing if www.gooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooogle.com is a valid authority =  " + result);
	   System.out.println("\n");	   
	   
	   //test invalid ascii chars in url
	   String firstPart= "www.googl";
	   char invalidChar = 192;
	   String lastPart = ".com";
	   firstPart = firstPart + invalidChar + lastPart;  //forms string to test
	   result = urlVal.isValid(firstPart);
	   System.out.println("Testing if" + firstPart + "is valid url =  " + result);
	   System.out.println("\n");	   

	   
	   //test invalid schemes  
	   /*https://en.wikipedia.org/wiki/Uniform_Resource_Locator
	    * The scheme, consisting of a sequence of characters beginning 
	    * with a letter and followed by any combination of letters, digits,
	    * plus (+), period (.), or hyphen (-). Although schemes are case-insensitive,
	    * the canonical form is lowercase and documents that specify schemes must 
	    * do so with lowercase letters.
	    */
	   
	   
	   //test invalid number leading scheme  
	   result =  urlVal.isValidScheme("3http");
	   System.out.println("Testing if 3http is valid scheme =  " + result);
	   System.out.println("\n");	   
	   
	   //test invalid symbol in scheme
	   result =  urlVal.isValidScheme("h!ttp");
	   System.out.println("Testing if h!ttp is valid scheme =  " + result);
	   System.out.println("\n");	
	   
	   //test invalid symbol in scheme    //Bugg found don't think xyz is a valid scheme
	   result =  urlVal.isValidScheme("xyz");
	   System.out.println("Testing if xyz is valid scheme =  " + result);
	   System.out.println("\n");

	   //test empty scheme
	   result =  urlVal.isValidScheme("");
	   System.out.println("Testing if no scheme is a valid scheme =  " + result);
	   System.out.println("\n");	
	   
	  /* https://en.wikipedia.org/wiki/Uniform_Resource_Locator
	   An authority part, comprising: An optional authentication section of a user name and password, separated by a colon, followed by an at symbol (@)
	   A "host", consisting of either a registered name (including but not limited to a hostname), or an IP address.
	  
	  Hostnames are composed of series of labels concatenated with dots, as are all domain names. For example, 
	  "en.wikipedia.org" is a hostname. Each label must be between 1 and 63 characters long,[2] and the 
	  entire hostname (including the delimiting dots but not a trailing dot) has a maximum of 253 ASCII 
	  characters.[3]

	The Internet standards (Requests for Comments) for protocols mandate that component hostname labels may 
	contain only the ASCII letters 'a' through 'z' (in a case-insensitive manner), the digits '0' through '9', 
	and the hyphen ('-'). The original specification of hostnames in RFC 952, mandated that labels could not 
	start with a digit or with a hyphen, and must not end with a hyphen. However, a subsequent specification 
	(RFC 1123) permitted hostname labels to start with digits. No other symbols, punctuation characters, or 
	white space are permitted.

	  *
	  */
	   
	   //test empty authroity
	   result = urlVal.isValidAuthority("");
	   System.out.println("Testing if no authority is a valid authority =  " + result);
	   System.out.println("\n");	
	   
	   //ip address out of range IE last valid address 223.255.255.255
	   result = urlVal.isValidAuthority("488.255.255.256");
	   System.out.println("Testing if 488.255.255.256 authority is a valid authority =  " + result);
	   System.out.println("\n");
	   
	   // negative ip address out of range IE last valid address 223.255.255.255
	   result = urlVal.isValidAuthority("-224.235.225.187");
	   System.out.println("Testing if -224.235.225.187 authority is a valid authority =  " + result);
	   System.out.println("\n");
	   
	   
	   //no periods
	   result = urlVal.isValidAuthority("wwwgooglecom");
	   System.out.println("Testing if wwwgooglecom is a valid authority =  " + result);
	   System.out.println("\n");		   
	   
	   // to long of label
	   result = urlVal.isValidAuthority("www.gooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooogle.com");
	   System.out.println("Testing if www.gooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooogle.com is a valid authority =  " + result);
	   System.out.println("\n");	   

	   //invalid chars in label
	   result = urlVal.isValidAuthority("www.go*ogle.com");
	   System.out.println("Testing if www.go*ogle.com is a valid authority =  " + result);
	   System.out.println("\n");	   

	   //invalid top level domian
	   result = urlVal.isValidAuthority("www.google.ccm");
	   System.out.println("Testing if www.google.ccm is a valid authority =  " + result);
	   System.out.println("\n");	   	   
	   
	   /*
	    * A path, which contains data, usually organized in hierarchical form, that appears as 
	    * a sequence of segments separated by slashes. Such a sequence may resemble or map exactly 
	    * to a file system path, but does not always imply a relation to one.[14] The path must begin 
	    * with a single slash (/) if an authority part was present, and may also if one was not, but 
	    * must not begin with a double slash.
	    */
	   
	   //invalid path starting with double slash
	   result = urlVal.isValidPath("//doubleslashstart");
	   System.out.println("Testing if //doubleslashstart is a valid path =  " + result);
	   System.out.println("\n");	  
	   
	   //invalid use of double slash
	   result = urlVal.isValidPath("/topLevel//nextLevel");
	   System.out.println("Testing if /topLevel//nextLevel is a valid path =  " + result);
	   System.out.println("\n");	
	   
	   //invalid character
	   result = urlVal.isValidPath("/}/");
	   System.out.println("Testing if /}/  is a valid path =  " + result);
	   System.out.println("\n");	
	   
	   //invalid use of back slash
	   result = urlVal.isValidPath("/topLevel\\/nextLevel");
	   System.out.println("Testing if /topLevel\\/nextLevel is a valid path =  " + result);
	   System.out.println("\n");	
	   
	   /*
	    * An optional query, separated from the preceding part by a question mark (?), containing 
	    * a query string of non-hierarchical data. Its syntax is not well defined, but by convention 
	    * is most often a sequence of attribute–value pairs separated by a delimiter.
	    */
	   
	   //invalid query doesn't start with a question mark
	   result = urlVal.isValidQuery("noQuestionMark=bad");
	   System.out.println("Testing if noQuestionMark=bad is a valid query =  " + result);
	   System.out.println("\n");	 
	   
	   //invalid query delimiter 
	   result = urlVal.isValidQuery("?value1=2+value2=3");
	   System.out.println("Testing if ?value1=2+value2=3 is a valid query =  " + result);
	   System.out.println("\n");	    
	   
	   
	   //calling isValid to increase coverage
	  
	   //invalid scheme
	   result = urlVal.isValid("3http://www.google.com");
	   System.out.println("Testing if 3http://www.google.com is valid url =  " + result);
	   System.out.println("\n");
	   
	   //invalid authroity
	   result = urlVal.isValid("http://www.go*ogle.com");
	   System.out.println("Testing if http://www.go*ogle.com is valid url =  " + result);
	   System.out.println("\n");	   
	   
	   //invalid path
	   result = urlVal.isValid("http://www.google.com//path");
	   System.out.println("Testing if http://www.google.com//path is valid url =  " + result);
	   System.out.println("\n");	   

	   
	   //invalid query
	   result = urlVal.isValid("http://www.google.com?value1=2+value2=3");
	   System.out.println("Testing if http://www.google.com?value1=2+value2=3 is valid url =  " + result);
	   System.out.println("\n");	   
	   

   }
   
   public void testYourSecondPartition()
   {
	   //valid parts and full valid urls
	   
 
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //long url test
	   boolean result;
	   result = urlVal.isValid("http://www.goooooooooooooooooooooooooogle.com");
	   System.out.println("Testing if http://www.goooooooooooooooooooooooooogle.com is a valid url =  " + result);
	   System.out.println("\n");	   
	   
 
	   
	   //test normal url
	   
	   result = urlVal.isValid("http://www.google.com");
	   System.out.println("Testing if http://www.google.com is valid url =  " + result);
	   System.out.println("\n");	   

	   
	   //test valid schemes  
	   /*https://en.wikipedia.org/wiki/Uniform_Resource_Locator
	    * The scheme, consisting of a sequence of characters beginning 
	    * with a letter and followed by any combination of letters, digits,
	    * plus (+), period (.), or hyphen (-). Although schemes are case-insensitive,
	    * the canonical form is lowercase and documents that specify schemes must 
	    * do so with lowercase letters.
	    */
	   
	   
	   //test invalid number leading scheme  
	   result =  urlVal.isValidScheme("http");
	   System.out.println("Testing if http is valid scheme =  " + result);
	   System.out.println("\n");	   
	   
	   //test valid symbol in scheme
	   result =  urlVal.isValidScheme("mailto");
	   System.out.println("Testing if mailto is valid scheme =  " + result);
	   System.out.println("\n");	
	   
	   //test valid symbol in scheme    
	   result =  urlVal.isValidScheme("ftp");
	   System.out.println("Testing if ftp is valid scheme =  " + result);
	   System.out.println("\n");

	   
	  /* https://en.wikipedia.org/wiki/Uniform_Resource_Locator
	   An authority part, comprising: An optional authentication section of a user name and password, separated by a colon, followed by an at symbol (@)
	   A "host", consisting of either a registered name (including but not limited to a hostname), or an IP address.
	  
	  Hostnames are composed of series of labels concatenated with dots, as are all domain names. For example, 
	  "en.wikipedia.org" is a hostname. Each label must be between 1 and 63 characters long,[2] and the 
	  entire hostname (including the delimiting dots but not a trailing dot) has a maximum of 253 ASCII 
	  characters.[3]

	The Internet standards (Requests for Comments) for protocols mandate that component hostname labels may 
	contain only the ASCII letters 'a' through 'z' (in a case-insensitive manner), the digits '0' through '9', 
	and the hyphen ('-'). The original specification of hostnames in RFC 952, mandated that labels could not 
	start with a digit or with a hyphen, and must not end with a hyphen. However, a subsequent specification 
	(RFC 1123) permitted hostname labels to start with digits. No other symbols, punctuation characters, or 
	white space are permitted.

	  *
	  */
	   
	
	   
	   //ip address in range IE last valid address 223.255.255.255
	   result = urlVal.isValidAuthority("223.255.255.255");
	   System.out.println("Testing if 223.255.255.255 authority is a valid authority =  " + result);
	   System.out.println("\n");
	   
	   
	   
	   //proper authority
	   result = urlVal.isValidAuthority("www.google.com");
	   System.out.println("Testing if www.google.com is a valid authority =  " + result);
	   System.out.println("\n");		   
	   

	   

	   //valid top level domian
	   result = urlVal.isValidAuthority("www.charity.org");
	   System.out.println("Testing if www.charity.org is a valid authority =  " + result);
	   System.out.println("\n");	   	   
	   
	   /*
	    * A path, which contains data, usually organized in hierarchical form, that appears as 
	    * a sequence of segments separated by slashes. Such a sequence may resemble or map exactly 
	    * to a file system path, but does not always imply a relation to one.[14] The path must begin 
	    * with a single slash (/) if an authority part was present, and may also if one was not, but 
	    * must not begin with a double slash.
	    */
	   
	   //valid path starting with slash
	   result = urlVal.isValidPath("/singleslashstart");
	   System.out.println("Testing if /singleslashstart is a valid path =  " + result);
	   System.out.println("\n");	  
	   
	   //valid use of slash
	   result = urlVal.isValidPath("/topLevel/nextLevel/paper.doc");
	   System.out.println("Testing if /topLevel/nextLevel/paper.doc is a valid path =  " + result);
	   System.out.println("\n");	
	   

	   

	   
	   /*
	    * An optional query, separated from the preceding part by a question mark (?), containing 
	    * a query string of non-hierarchical data. Its syntax is not well defined, but by convention 
	    * is most often a sequence of attribute–value pairs separated by a delimiter.
	    */
	   
	   //valid query does start with a question mark
	   result = urlVal.isValidQuery("?QuestionMark=good");
	   System.out.println("Testing if ?QuestionMark=good is a valid query =  " + result);
	   System.out.println("\n");	 
	   
	   //valid query delimiter 
	   result = urlVal.isValidQuery("?value1=2;value2=3");
	   System.out.println("Testing if ?value1=2;value2=3 is a valid query =  " + result);
	   System.out.println("\n");	    
	   
	   
	   //calling isValid to increase coverage
	  
	   //valid url
	   result = urlVal.isValid("http://www.google.com");
	   System.out.println("Testing if http://www.google.com is valid url =  " + result);
	   System.out.println("\n");

	   
	   //valid url
	   result = urlVal.isValid("http://example.com?name=ferret");
	   System.out.println("Testing if http://example.com/over/there?name=ferret is valid url =  " + result);
	   System.out.println("\n");	   
	   
	   
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