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


import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import org.apache.commons.io.FileUtils;




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
	   System.out.println("*****Manual Tests*****");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String URL;
	   System.out.println("URL | Exepected | Actual");
	   URL = "http://www.amazon.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http:/www.amazon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http//www.amazon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "htp://www.amazon.com";
	   System.out.println(URL + " | false |" + urlVal.isValid(URL));
	   URL = "ftp://www.amazon.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "ftp:www.amazon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http:www.amazon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "h3t://www.amazon.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "www.amazon.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "3ht://www.amazon.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "net://www.amazon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://amazon.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://amazon.cc";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://abcde";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://1234.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://9.8.7.6.5";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com:5";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com:abc";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com:-7";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com/link1";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com//link1";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com/./link1";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com/link1/link2";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com?form=true";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com?form=true&name=false";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://www.ama?zon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.ama zon.com";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://#";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "foo.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "rdar://1234";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://foo.bar/foo(bar)baz quux";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://-error-.invalid";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://.www.foo.bar/";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://www.amazon.com./";
	   System.out.println(URL + " | false | " + urlVal.isValid(URL));
	   URL = "http://foo.com/blah_(wikipedia)_blah#cite-1";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://j.mp";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://userid:password@example.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://a.b-c.de";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://foo.com/blah_blah_(wikipedia)_(again)";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
	   URL = "http://-.~_!$&'()*+,;=:%40:80%2f::::::@example.com";
	   System.out.println(URL + " | true | " + urlVal.isValid(URL));
   }
   
   
   public void testYourFirstPartition()
   {
	   System.out.println("\n");
	   System.out.println("*****Partition Tests*****");
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
	    * is most often a sequence of attributevalue pairs separated by a delimiter.
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
	    * is most often a sequence of attributevalue pairs separated by a delimiter.
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
   
   
   public void testIsValid() throws IOException
   {
	   System.out.println("\n");
	   System.out.println("*****Unit Tests*****");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   
	   //These are all the pieces of a url.  If a string is allowed use piece("string", true)
	   piece[] schemes = {
			   new piece("", false),   // Note: I changed this
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
			   new piece("host", true),
			   new piece("", false),
			   new piece("www.host",true),
			   new piece("host123",true),
			   new piece("123",true),
			   new piece("1.2.3", false),
			   new piece("255.255.255.255",true),
			   new piece("hhh.",false),
	   };
	   piece[] hosts = {
			new piece("", false),   
		   new piece("com", true),
		   new piece("ac", true),                 // Ascension Island
	       new piece("ad", true),                 // Andorra
	       new piece("ae", true),                 // United Arab Emirates
	       new piece("af", true),                 // Afghanistan
/*	       new piece("ag", true),                 // Antigua and Barbuda
	       new piece("ai", true),                 // Anguilla
	       new piece("al", true),                 // Albania
	       new piece("am", true),                 // Armenia
	       new piece("an", true),                 // Netherlands Antilles
	       new piece("ao", true),                 // Angola
	       new piece("aq", true),                 // Antarctica
	       new piece("ar", true),                 // Argentina
	       new piece("as", true),                 // American Samoa
	       new piece("at", true),                 // Austria
	       new piece("au", true),                 // Australia (includes Ashmore and Cartier Islands and Coral Sea Islands)
	       new piece("aw", true),                 // Aruba
	       new piece("ax", true),                 // Åland
	       new piece("az", true),                 // Azerbaijan
	       new piece("ba", true),                 // Bosnia and Herzegovina
	       new piece("bb", true),                 // Barbados
	       new piece("bd", true),                 // Bangladesh
	       new piece("be", true),                 // Belgium
	       new piece("bf", true),                 // Burkina Faso
	       new piece("bg", true),                 // Bulgaria
	       new piece("bh", true),                 // Bahrain
	       new piece("bi", true),                 // Burundi
	       new piece("bj", true),                 // Benin
	       new piece("bm", true),                 // Bermuda
	       new piece("bn", true),                 // Brunei Darussalam
	       new piece("bo", true),                 // Bolivia
	       new piece("br", true),                 // Brazil
	       new piece("bs", true),                 // Bahamas
	       new piece("bt", true),                 // Bhutan
	       new piece("bv", true),                 // Bouvet Island
	       new piece("bw", true),                 // Botswana
	       new piece("by", true),                 // Belarus
	       new piece("bz", true),                 // Belize
	       new piece("ca", true),                 // Canada
	       new piece("cc", true),                 // Cocos (Keeling) Islands
	       new piece("cd", true),                 // Democratic Republic of the Congo (formerly Zaire)
	       new piece("cf", true),                 // Central African Republic
	       new piece("cg", true),                 // Republic of the Congo
	       new piece("ch", true),                 // Switzerland
	       new piece("ci", true),                 // Côte d'Ivoire
	       new piece("ck", true),                 // Cook Islands
	       new piece("cl", true),                 // Chile
	       new piece("cm", true),                 // Cameroon
	       new piece("cn", true),                 // China, true), mainland
	       new piece("co", true),                 // Colombia
	       new piece("cr", true),                 // Costa Rica
	       new piece("cu", true),                 // Cuba
	       new piece("cv", true),                 // Cape Verde
	       new piece("cx", true),                 // Christmas Island
	       new piece("cy", true),                 // Cyprus
	       new piece("cz", true),                 // Czech Republic
	       new piece("de", true),                 // Germany
	       new piece("dj", true),                 // Djibouti
	       new piece("dk", true),                 // Denmark
	       new piece("dm", true),                 // Dominica
	       new piece("do", true),                 // Dominican Republic
	       new piece("dz", true),                 // Algeria
	       new piece("ec", true),                 // Ecuador
	       new piece("ee", true),                 // Estonia
	       new piece("eg", true),                 // Egypt
	       new piece("er", true),                 // Eritrea
	       new piece("es", true),                 // Spain
	       new piece("et", true),                 // Ethiopia
	       new piece("eu", true),                 // European Union
	       new piece("fi", true),                 // Finland
	       new piece("fj", true),                 // Fiji
	       new piece("fk", true),                 // Falkland Islands
	       new piece("fm", true),                 // Federated States of Micronesia
	       new piece("fo", true),                 // Faroe Islands
	       new piece("fr", true),                 // France
	       new piece("ga", true),                 // Gabon
	       new piece("gb", true),                 // Great Britain (United Kingdom)
	       new piece("gd", true),                 // Grenada
	       new piece("ge", true),                 // Georgia
	       new piece("gf", true),                 // French Guiana
	       new piece("gg", true),                 // Guernsey
	       new piece("gh", true),                 // Ghana
	       new piece("gi", true),                 // Gibraltar
	       new piece("gl", true),                 // Greenland
	       new piece("gm", true),                 // The Gambia
	       new piece("gn", true),                 // Guinea
	       new piece("gp", true),                 // Guadeloupe
	       new piece("gq", true),                 // Equatorial Guinea
	       new piece("gr", true),                 // Greece
	       new piece("gs", true),                 // South Georgia and the South Sandwich Islands
	       new piece("gt", true),                 // Guatemala
	       new piece("gu", true),                 // Guam
	       new piece("gw", true),                 // Guinea-Bissau
	       new piece("gy", true),                 // Guyana
	       new piece("hk", true),                 // Hong Kong
	       new piece("hm", true),                 // Heard Island and McDonald Islands
	       new piece("hn", true),                 // Honduras
	       new piece("hr", true),                 // Croatia (Hrvatska)
	       new piece("ht", true),                 // Haiti
	       new piece("hu", true),                 // Hungary
	       new piece("id", true),                 // Indonesia
	       new piece("ie", true),                 // Ireland (Éire)
	       new piece("il", true),                 // Israel
	       new piece("im", true),                 // Isle of Man
	       new piece("in", true),                 // India
	       new piece("io", true),                 // British Indian Ocean Territory
	       new piece("iq", true),                 // Iraq
	       new piece("ir", true),                 // Iran
	       new piece("is", true),                 // Iceland
	       new piece("it", true),                 // Italy
	       new piece("je", true),                 // Jersey
	       new piece("jm", true),                 // Jamaica
	       new piece("jo", true),                 // Jordan
	       new piece("jp", true),                 // Japan
	       new piece("ke", true),                 // Kenya*/
	       new piece("kg", true),                 // Kyrgyzstan
	       new piece("kh", true),                 // Cambodia (Khmer)
	       new piece("ki", true),                 // Kiribati
	       new piece("km", true),                 // Comoros
	       new piece("kn", true),                 // Saint Kitts and Nevis
	       new piece("kp", true),                 // North Korea
	       new piece("kr", true),                 // South Korea
	       new piece("kw", true),                 // Kuwait
	       new piece("ky", true),                 // Cayman Islands
	       new piece("kz", true),                 // Kazakhstan
	       new piece("la", true),                 // Laos (currently being marketed as the official domain for Los Angeles)
	       new piece("lb", true),                 // Lebanon
	       new piece("lc", true),                 // Saint Lucia
	       new piece("li", true),                 // Liechtenstein
	       new piece("lk", true),                 // Sri Lanka
	       new piece("lr", true),                 // Liberia
	       new piece("ls", true),                 // Lesotho
	       new piece("lt", true),                 // Lithuania
	       new piece("lu", true),                 // Luxembourg
	       new piece("lv", true),                 // Latvia
	       new piece("ly", true),                 // Libya
	       new piece("ma", true),                 // Morocco
	       new piece("mc", true),                 // Monaco
/*	       new piece("md", true),                 // Moldova
	       new piece("me", true),                 // Montenegro
	       new piece("mg", true),                 // Madagascar
	       new piece("mh", true),                 // Marshall Islands
	       new piece("mk", true),                 // Republic of Macedonia
	       new piece("ml", true),                 // Mali
	       new piece("mm", true),                 // Myanmar
	       new piece("mn", true),                 // Mongolia
	       new piece("mo", true),                 // Macau
	       new piece("mp", true),                 // Northern Mariana Islands
	       new piece("mq", true),                 // Martinique
	       new piece("mr", true),                 // Mauritania
	       new piece("ms", true),                 // Montserrat
	       new piece("mt", true),                 // Malta
	       new piece("mu", true),                 // Mauritius
	       new piece("mv", true),                 // Maldives
	       new piece("mw", true),                 // Malawi
	       new piece("mx", true),                 // Mexico
	       new piece("my", true),                 // Malaysia
	       new piece("mz", true),                 // Mozambique
	       new piece("na", true),                 // Namibia
	       new piece("nc", true),                 // New Caledonia
	       new piece("ne", true),                 // Niger
	       new piece("nf", true),                 // Norfolk Island
	       new piece("ng", true),                 // Nigeria
	       new piece("ni", true),                 // Nicaragua
	       new piece("nl", true),                 // Netherlands
	       new piece("no", true),                 // Norway
	       new piece("np", true),                 // Nepal
	       new piece("nr", true),                 // Nauru
	       new piece("nu", true),                 // Niue
	       new piece("nz", true),                 // New Zealand
	       new piece("om", true),                 // Oman
	       new piece("pa", true),                 // Panama
	       new piece("pe", true),                 // Peru
	       new piece("pf", true),                 // French Polynesia With Clipperton Island
	       new piece("pg", true),                 // Papua New Guinea
	       new piece("ph", true),                 // Philippines
	       new piece("pk", true),                 // Pakistan
	       new piece("pl", true),                 // Poland
	       new piece("pm", true),                 // Saint-Pierre and Miquelon
	       new piece("pn", true),                 // Pitcairn Islands
	       new piece("pr", true),                 // Puerto Rico
	       new piece("ps", true),                 // Palestinian territories (PA-controlled West Bank and Gaza Strip)
	       new piece("pt", true),                 // Portugal
	       new piece("pw", true),                 // Palau
	       new piece("py", true),                 // Paraguay
	       new piece("qa", true),                 // Qatar
	       new piece("re", true),                 // Réunion
	       new piece("ro", true),                 // Romania
	       new piece("rs", true),                 // Serbia
	       new piece("ru", true),                 // Russia
	       new piece("rw", true),                 // Rwanda
	       new piece("sa", true),                 // Saudi Arabia
	       new piece("sb", true),                 // Solomon Islands
	       new piece("sc", true),                 // Seychelles
	       new piece("sd", true),                 // Sudan
	       new piece("se", true),                 // Sweden
	       new piece("sg", true),                 // Singapore
	       new piece("sh", true),                 // Saint Helena
	       new piece("si", true),                 // Slovenia
	       new piece("sj", true),                 // Svalbard and Jan Mayen Islands Not in use (Norwegian dependencies; see .no)
	       new piece("sk", true),                 // Slovakia
	       new piece("sl", true),                 // Sierra Leone
	       new piece("sm", true),                 // San Marino
	       new piece("sn", true),                 // Senegal
	       new piece("so", true),                 // Somalia
	       new piece("sr", true),                 // Suriname
	       new piece("st", true),                 // São Tomé and Príncipe
	       new piece("su", true),                 // Soviet Union (deprecated)
	       new piece("sv", true),                 // El Salvador
	       new piece("sy", true),                 // Syria
	       new piece("sz", true),                 // Swaziland
	       new piece("tc", true),                 // Turks and Caicos Islands
	       new piece("td", true),                 // Chad
	       new piece("tf", true),                 // French Southern and Antarctic Lands
	       new piece("tg", true),                 // Togo
	       new piece("th", true),                 // Thailand
	       new piece("tj", true),                 // Tajikistan
	       new piece("tk", true),                 // Tokelau
	       new piece("tl", true),                 // East Timor (deprecated old code)
	       new piece("tm", true),                 // Turkmenistan
	       new piece("tn", true),                 // Tunisia
	       new piece("to", true),                 // Tonga
	       new piece("tp", true),                 // East Timor
	       new piece("tr", true),                 // Turkey*/
	       new piece("tt", true),                 // Trinidad and Tobago
	       new piece("tv", true),                 // Tuvalu
	       new piece("tw", true),                 // Taiwan, true), Republic of China
	       new piece("tz", true),                 // Tanzania
	       new piece("ua", true),                 // Ukraine
/*	       new piece("ug", true),                 // Uganda
	       new piece("uk", true),                 // United Kingdom
	       new piece("um", true),                 // United States Minor Outlying Islands
	       new piece("us", true),                 // United States of America
	       new piece("uy", true),                 // Uruguay
	       new piece("uz", true),                 // Uzbekistan
	       new piece("va", true),                 // Vatican City State
	       new piece("vc", true),                 // Saint Vincent and the Grenadines
	       new piece("ve", true),                 // Venezuela
	       new piece("vg", true),                 // British Virgin Islands
	       new piece("vi", true),                 // U.S. Virgin Islands
	       new piece("vn", true),                 // Vietnam
	       new piece("vu", true),                 // Vanuatu
	       new piece("wf", true),                 // Wallis and Futuna
	       new piece("ws", true),                 // Samoa (formerly Western Samoa)
	       new piece("ye", true),                 // Yemen
	       new piece("yt", true),                 // Mayotte
	       new piece("yu", true),                 // Serbia and Montenegro (originally Yugoslavia)
	       new piece("za", true),                 // South Africa
	       new piece("zm", true),                 // Zambia
	       new piece("zw", true),                 // Zimbabwe*/
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
	  

       
	   int count = 0;
	   
	   FileUtils.writeStringToFile(new File("test.csv"), "Result,URL,Expected,Actual,\n", true);
	   for(piece scheme : schemes){
		   for (piece authorityUserNamePW : authorityUserNamePWs){
			   for (piece authorityHost : authorityHosts){
				   for (piece host: hosts){
					   for(piece port : ports){
						   for (piece slashes : slashess){
							   for (piece path : paths){
								   for (piece query : queries){
									   for(piece fragment : fragments){
								  
			if(authorityHost.part.equals("255.255.255.255") && !host.part.equals("")){
				authorityHost.isValid = false;
			}
			String period = "";
			if(!host.part.equals("")){
				period = ".";
			}


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
		   

									   
		   	String url = scheme.part + slashes.part + authorityUserNamePW.part + authorityHost.part + period + host.part + port.part + path.part + query.part + fragment.part;
		   	boolean urlValResult = urlVal.isValid(url);
		   	boolean validURL = scheme.isValid && slashes.isValid && authorityUserNamePW.isValid && authorityHost.isValid && host.isValid && port.isValid && path.isValid && query.isValid && fragment.isValid;
		   	
	//	   	System.out.println("\n");
		   	


		   	
		   	String results = "";
		   if(urlValResult == validURL){
			   results = "SUCCESS" + "," + url + "," + validURL + "," + urlValResult + "," + "\n";
		   }
		   else{
			   results = "FAILURE" + "," + url + "," + validURL + "," + urlValResult + "," + "\n";
		   }
		   FileUtils.writeStringToFile(new File("test.csv"), results, true);
		   count += 5;
		   if(count > 1000000){
			   return;
		   }

									   
	   }}}}}}}}

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
   class piece{
	   String part;
	   boolean isValid;
	   
   public piece (String part, boolean isValid){
	   this.part = part;
	   this.isValid = isValid;
   }
   }

}
