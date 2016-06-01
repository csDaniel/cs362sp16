There are 9 reports in the test below.
I've classified 6 of them as bugs, 2 as code deficiencies, and 1 as an issue of interest.



=================================================
Bug Report #1
=================================================

Title: urlValidator fails to recognize valid URL queries

Class: Serious Bug
Priority: High

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns FALSE when queries are included

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://www.example.com/wpstyle/?a=b");
  assertEquals(true, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  Pattern matcher boolean return value is switched with a logical NOT (!) operator

  return !QUERY_PATTERN.matcher(query).matches();
  ...  should be ...
  return QUERY_PATTERN.matcher(query).matches();

Filename: URLValidator.java
Line number(s): 446

Other notes: None.




=================================================
Bug Report #2
=================================================

Title: urlValidator fails to recognize valid port numbers

Class: Serious Bug
Priority: High

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns FALSE when port number > 999

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://www.amazon.com:999");
  assertEquals(true, result); // this assertion passes
  result = urlVal.isValid("http://www.amazon.com:1000");
  assertEquals(true, result); // this assertion fails

Workarounds: Only use port numbers less than 1000.

Cause Determination
=================================================

Summary:
  Invalid regex for port number comparison.

  private static final String PORT_REGEX = "^:(\\d{1,3})$";
  ...  should be ...
  modification needed to allow 5 characters (but only up to 65535)

Filename: URLValidator.java
Line number(s): 158

Other notes: None.




=================================================
Bug Report #3
=================================================

Title: urlValidator fails to recognize valid port numbers

Class: Serious Bug
Priority: High

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns TRUE for all IP addresses
  between 0.0.0.0 and 999.999.999.999

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://0.0.0.0");
  assertEquals(false, result); // this assertion fails
  result = urlVal.isValid("http://999.999.999.999");
  assertEquals(false, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  Invalid return value on IP segment check.

  if (iIpSegment > 255) {
    return true;
  }
  ...  should be ...
  if (iIpSegment > 255) {
    return false;
  }

Filename: InetAddressValidator.java
Line number(s): 94-98

Other notes: There is a deficiency in the code in that there is no
  checking at all for IP addresses in the reserved range.




=================================================
Bug Report #4
=================================================

Title: urlValidator fails to recognize some valid country code TLDs

Class: Serious Bug
Priority: High

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns FALSE for URLs containing some
    country code TLDs and TRUE for others

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://a.it");
  assertEquals(true, result); // this assertion passes
  boolean result = urlVal.isValid("http://a.ws");
  assertEquals(true, result); // this assertion fails
  boolean result = urlVal.isValid("http://j.mp");
  assertEquals(true, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  Incomplete list of country code TLDs for comparison

Filename: DomainValidator.java
Line number(s): 248-359

Other notes: None.




=================================================
Bug Report #5
=================================================

Title: urlValidator fails to recognize some valid generic TLDs

Class: Serious Bug
Priority: Medium

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns FALSE for URLs containing some
    generic TLDs and TRUE for others

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://foo.com");
  assertEquals(true, result); // this assertion passes
  boolean result = urlVal.isValid("http://foo.bar");
  assertEquals(true, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  Incomplete list of generic TLDs for comparison

Filename: DomainValidator.java
Line number(s): 225-246

Other notes: None.




=================================================
Bug Report #6
=================================================

Title: urlValidator fails to differentiate between valid and invalid URL fragments

Class: Code Deficiency
Priority: Medium

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns TRUE for all URL fragments when using the
    ALLOW_ALL_SCHEMES option, it only returns FALSE when NO_FRAGMENTS option is selected

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://www.somesite.com/somepage.html#somefragment");
  assertEquals(true, result); // this assertion passes
  boolean result = urlVal.isValid("http://www.somesite.com/somepage.html#%");
  assertEquals(false, result); // this assertion fails

  UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
  result = urlVal2.isValid("http://www.somesite.com/somepage.html#somefragment");
  assertEquals(false, result); // this assertion passes

Workarounds: None.

Cause Determination
=================================================

Summary:
  isValidFragment() function is deficient in that it only checks for NULL fragments and
    for the NO_FRAGMENTS option, it doesn't actually do any allowed character or format
    validation of the fragment itself

Filename: DomainValidator.java
Line number(s): 454-460

Other notes: None.




=================================================
Bug Report #7
=================================================

Title: urlValidator returns FALSE when user/pass are included in URL authority

Class: Code Deficiency
Priority: High

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns FALSE when user/pass are included in URL authority

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  boolean result = urlVal.isValid("http://username:password@example.com");
  assertEquals(true, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  urlValidator assumes that authority portion of URL will be either a hostname or IP address
    and as such doesn't at all consider user/pass formatted authority, the following line
    returns 'username' as hostname - should be 'example.com'

    String hostLocation = authorityMatcher.group(PARSE_AUTHORITY_HOST_IP);

Filename: UrlValidator.java
Line number(s): 377-389

Other notes: None.




=================================================
Bug Report #8
=================================================

Title: urlValidator returns FALSE when testing local URLs

Class: Serious Bug
Priority: Medium

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator .isValid() method returns FALSE when testing local URLs even when using ALLOW_LOCAL_URLS option

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
  boolean result = urlVal.isValid("http://localhost");
  assertEquals(true, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  hostnameRegex check return value is switched with a logical NOT (!) operator

  if (!hostnameRegex.isValid(domain)) {
  ...  should be ...
  if (hostnameRegex.isValid(domain)) {

Filename: DomainValidator.java
Line number(s): 139

Other notes: None.




=================================================
Bug Report #9
=================================================

Title: urlValidator returns FALSE when testing URLs containing Unicode (non-ASCII characters)

Class: Issue Of Interest
Priority: Low

Date: 29 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: URLValidator
Platform: Windows 10
Reproducible: Yes

Description
=================================================

Summary:
  urlValidator returns FALSE when testing URLs containing Unicode (non-ASCII characters)

Inputs to reproduce:
  UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
  boolean result = urlVal.isValid("http://例子.测试");
  assertEquals(true, result); // this assertion fails

Workarounds: None.

Cause Determination
=================================================

Summary:
  urlValidator specifically checks for ASCII characters and returns FALSE for non-ASCII
    on the following line of code:

  if (!ASCII_PATTERN.matcher(value).matches()) {

Filename: URLValidator.java
Line number(s): 285

Other notes: I have tagged this as an issue rather than a bug.  It is unclear whether or
  not this is intended behavior.  I suspect that it is becuase there is a specific check
  for ASCII characters.  Read more here: https://www.w3.org/International/articles/idn-and-iri/
