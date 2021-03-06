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

   
   
   public void testManualTest()
   {
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
     // testing valid URLs
     System.out.println("Valid URLs");
     System.out.println("http://www.amazon.com - " + urlVal.isValid("http://www.amazon.com"));
     System.out.println("http://www.images.google.com - " + urlVal.isValid("http://www.images.google.com"));
     System.out.println("http://www.example.com/index.html - " + urlVal.isValid("http://www.example.com/index.html"));
     
     System.out.println("foo://example.com:8042/over/there?name=ferret#nose - " + urlVal.isValid("foo://example.com:8042/over/there?name=ferret#nose"));
     System.out.println("http://www.example.com:8042/over/there?name=ferret#nose - " + urlVal.isValid("http://www.example.com:8042/over/there?name=ferret#nose"));
     System.out.println("http://www.example.com:8042 - " + urlVal.isValid("http://www.example.com:8042"));
     System.out.println("http://www.example.com:804 - " + urlVal.isValid("http://www.example.com:804"));
    
     System.out.println("http://www.ietf.org/rfc/rfc2396.txt - " + urlVal.isValid("http://www.ietf.org/rfc/rfc2396.txt"));
     
     System.out.println("ftp://ftp.is.co.za/rfc/rfc1808.txt - " + urlVal.isValid("ftp://ftp.is.co.za/rfc/rfc1808.txt"));
     System.out.println("ftp://ftp.is.com/rfc/rfc1808.txt - " + urlVal.isValid("ftp://ftp.is.com/rfc/rfc1808.txt"));
     System.out.println("http://www.google.co.za - " + urlVal.isValid("http://www.google.co.za"));
     
     System.out.println("telnet://192.0.2.16:80/ - " + urlVal.isValid("telnet://192.0.2.16:80/"));
     System.out.println("http://192.0.2.16:80/ - " + urlVal.isValid("http://192.0.2.16:80/"));

     System.out.println("http://www.example.com/index?test=false - " + urlVal.isValid("http://www.example.com/index?test=false"));
     System.out.println("http://www.example.com/index?test=false with spaces - " + urlVal.isValid("http://www.example.com/index?test=false with spaces"));
     System.out.println("http://www.example.com/index?2.3j=what - " + urlVal.isValid("http://www.example.com/index?2.3j=what"));
     
     // testing invalid URLs
     System.out.println("Invalid URLs");
     System.out.println("www.amazon.com - " + urlVal.isValid("www.amazon.com"));
     System.out.println("http://www.amazon - " + urlVal.isValid("http://www.amazon"));
     System.out.println("http://www.amazon:8042/ - " + urlVal.isValid("http://www.amazon:8042/"));
     System.out.println("telnet://192.0.2.257:80/ - " + urlVal.isValid("telnet://192.0.2.257:80/"));
     System.out.println("http://www.example.com//index.html - " + urlVal.isValid("http://www.example.com//index.html"));
     System.out.println("telnet://1200::AB00:1234::2552:7777:1313 - " + urlVal.isValid("telnet://1200::AB00:1234::2552:7777:1313/"));
     System.out.println("http://1200::AB00:1234::2552:7777:1313 - " + urlVal.isValid("http://1200::AB00:1234::2552:7777:1313"));
     
     
   }
   
 
}
