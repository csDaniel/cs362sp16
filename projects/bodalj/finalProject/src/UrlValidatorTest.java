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
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.Random;
import java.util.Set;
import java.util.HashSet;


/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest {

    @Before
    public void setUp() throws Exception {

    }

    @After
    public void tearDown() throws Exception {

    }

    /**
     * Testing valid port within authority
     */
    @Test
    public void testAuthorityPortInvalidNegative() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String schema = "http://";
        String authority = "www.google.com";
        StringBuilder url = new StringBuilder();
        url.append(schema);
        url.append(authority);
        url.append(":");
        String urlStr = url.toString();
        int minValidPort = 1;
        int maxValidPort = 65535;

        for (int i = -1000; i <= -1; i++) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(urlStr);
            tempUrl.append(i);
            expectedResult = i >= minValidPort && i <= maxValidPort ? true : false;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testAuthorityPortInvalidZero() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String schema = "http://";
        String authority = "www.google.com";
        StringBuilder url = new StringBuilder();
        url.append(schema);
        url.append(authority);
        url.append(":");
        String urlStr = url.toString();
        int minValidPort = 1;
        int maxValidPort = 65535;

        for (int i = 0; i <= 0; i++) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(urlStr);
            tempUrl.append(i);
            expectedResult = i >= minValidPort && i <= maxValidPort ? true : false;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testAuthorityPortValid() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String schema = "http://";
        String authority = "www.google.com";
        StringBuilder url = new StringBuilder();
        url.append(schema);
        url.append(authority);
        url.append(":");
        String urlStr = url.toString();
        int minValidPort = 1;
        int maxValidPort = 65535;

        for (int i = 1; i <= 65535; i++) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(urlStr);
            tempUrl.append(i);
            expectedResult = i >= minValidPort && i <= maxValidPort ? true : false;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testAuthorityPortInvalidPositive() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String schema = "http://";
        String authority = "www.google.com";
        StringBuilder url = new StringBuilder();
        url.append(schema);
        url.append(authority);
        url.append(":");
        String urlStr = url.toString();
        int minValidPort = 1;
        int maxValidPort = 65535;

        for (int i = 65536; i <= 70000; i++) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(urlStr);
            tempUrl.append(i);
            expectedResult = i >= minValidPort && i <= maxValidPort ? true : false;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testTldInfastructureValid() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String prefix = "http://www.google.";

        for (String tld : INFRASTRUCTURE_TLDS) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(prefix);
            tempUrl.append(tld);
            expectedResult = true;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testTldGenericValid() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String prefix = "http://www.google.";

        for (String tld : GENERIC_TLDS) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(prefix);
            tempUrl.append(tld);
            expectedResult = true;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testTldCountryCodeValid() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String prefix = "http://www.google.";

        for (String tld : COUNTRY_CODE_TLDS) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(prefix);
            tempUrl.append(tld);
            expectedResult = true;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testTldLocaleValid() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_LOCAL_URLS);
        boolean actualResult;
        boolean expectedResult;

        String prefix = "http://www.google.";

        for (String tld : LOCAL_TLDS) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(prefix);
            tempUrl.append(tld);
            expectedResult = true;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testTldRandomInvalid() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean actualResult;
        boolean expectedResult;

        String prefix = "http://www.google.";
        int numTests = 100000;
        int minLength = 1;
        int maxLength = 10;
        Random rng = new Random();
        int range = maxLength - minLength + 1;
        String characters = "abcdefghijklmnopqrstuvxwyz";

        Set<String> TLDS = new HashSet<String>();
        for (String s : INFRASTRUCTURE_TLDS) {
            TLDS.add(s);
        }
        for (String s : GENERIC_TLDS) {
            TLDS.add(s);
        }
        for (String s : COUNTRY_CODE_TLDS) {
            TLDS.add(s);
        }

        for (int i = 0; i < numTests; i++) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(prefix);
            int tldLength = rng.nextInt(range) + minLength;
            String tld = UrlValidatorTest.generateRandomString(new Random(), characters, tldLength);
            tempUrl.append(tld);
            expectedResult = TLDS.contains(tld) ? true : false;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    @Test
    public void testTldRandomInvalidWithLocalTLD() throws Exception {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES+UrlValidator.ALLOW_LOCAL_URLS);
        boolean actualResult;
        boolean expectedResult;

        String prefix = "http://www.google.";
        int numTests = 100000;
        int minLength = 1;
        int maxLength = 10;
        Random rng = new Random();
        int range = maxLength - minLength + 1;
        String characters = "abcdefghijklmnopqrstuvxwyz";

        Set<String> TLDS = new HashSet<String>();
        for (String s : INFRASTRUCTURE_TLDS) {
            TLDS.add(s);
        }
        for (String s : GENERIC_TLDS) {
            TLDS.add(s);
        }
        for (String s : COUNTRY_CODE_TLDS) {
            TLDS.add(s);
        }
        for (String s : LOCAL_TLDS) {
            TLDS.add(s);
        }

        for (int i = 0; i < numTests; i++) {
            StringBuilder tempUrl = new StringBuilder();
            tempUrl.append(prefix);
            int tldLength = rng.nextInt(range) + minLength;
            String tld = UrlValidatorTest.generateRandomString(new Random(), characters, tldLength);
            tempUrl.append(tld);
            expectedResult = TLDS.contains(tld) ? true : false;
            actualResult = urlVal.isValid(tempUrl.toString());
            String message = String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult);
            org.junit.Assert.assertEquals(message, actualResult, expectedResult);
        }
    }

    public static String generateRandomString(Random rng, String characters, int length) {
        char[] letters = new char[length];
        for (int i = 0; i < length; i++) {
            letters[i] = characters.charAt(rng.nextInt(characters.length()));
        }
        return new String(letters);
    }

    private static final String[] INFRASTRUCTURE_TLDS = new String[]{
            "arpa",               // internet infrastructure
            "root"                // diagnostic marker for non-truncated root zone
    };

    private static final String[] GENERIC_TLDS = new String[]{
            "aero",               // air transport industry
            "asia",               // Pan-Asia/Asia Pacific
            "biz",                // businesses
            "cat",                // Catalan linguistic/cultural community
            "com",                // commercial enterprises
            "coop",               // cooperative associations
            "info",               // informational sites
            "jobs",               // Human Resource managers
            "mobi",               // mobile products and services
            "museum",             // museums, surprisingly enough
            "name",               // individuals' sites
            "net",                // internet support infrastructure/business
            "org",                // noncommercial organizations
            "pro",                // credentialed professionals and entities
            "tel",                // contact data for businesses and individuals
            "travel",             // entities in the travel industry
            "gov",                // United States Government
            "edu",                // accredited postsecondary US education entities
            "mil",                // United States Military
            "int"                 // organizations established by international treaty
    };

    private static final String[] COUNTRY_CODE_TLDS = new String[]{
            "ac",                 // Ascension Island
            "ad",                 // Andorra
            "ae",                 // United Arab Emirates
            "af",                 // Afghanistan
            "ag",                 // Antigua and Barbuda
            "ai",                 // Anguilla
            "al",                 // Albania
            "am",                 // Armenia
            "an",                 // Netherlands Antilles
            "ao",                 // Angola
            "aq",                 // Antarctica
            "ar",                 // Argentina
            "as",                 // American Samoa
            "at",                 // Austria
            "au",                 // Australia (includes Ashmore and Cartier Islands and Coral Sea Islands)
            "aw",                 // Aruba
            "ax",                 // Åland
            "az",                 // Azerbaijan
            "ba",                 // Bosnia and Herzegovina
            "bb",                 // Barbados
            "bd",                 // Bangladesh
            "be",                 // Belgium
            "bf",                 // Burkina Faso
            "bg",                 // Bulgaria
            "bh",                 // Bahrain
            "bi",                 // Burundi
            "bj",                 // Benin
            "bm",                 // Bermuda
            "bn",                 // Brunei Darussalam
            "bo",                 // Bolivia
            "br",                 // Brazil
            "bs",                 // Bahamas
            "bt",                 // Bhutan
            "bv",                 // Bouvet Island
            "bw",                 // Botswana
            "by",                 // Belarus
            "bz",                 // Belize
            "ca",                 // Canada
            "cc",                 // Cocos (Keeling) Islands
            "cd",                 // Democratic Republic of the Congo (formerly Zaire)
            "cf",                 // Central African Republic
            "cg",                 // Republic of the Congo
            "ch",                 // Switzerland
            "ci",                 // Côte d'Ivoire
            "ck",                 // Cook Islands
            "cl",                 // Chile
            "cm",                 // Cameroon
            "cn",                 // China, mainland
            "co",                 // Colombia
            "cr",                 // Costa Rica
            "cu",                 // Cuba
            "cv",                 // Cape Verde
            "cx",                 // Christmas Island
            "cy",                 // Cyprus
            "cz",                 // Czech Republic
            "de",                 // Germany
            "dj",                 // Djibouti
            "dk",                 // Denmark
            "dm",                 // Dominica
            "do",                 // Dominican Republic
            "dz",                 // Algeria
            "ec",                 // Ecuador
            "ee",                 // Estonia
            "eg",                 // Egypt
            "er",                 // Eritrea
            "es",                 // Spain
            "et",                 // Ethiopia
            "eu",                 // European Union
            "fi",                 // Finland
            "fj",                 // Fiji
            "fk",                 // Falkland Islands
            "fm",                 // Federated States of Micronesia
            "fo",                 // Faroe Islands
            "fr",                 // France
            "ga",                 // Gabon
            "gb",                 // Great Britain (United Kingdom)
            "gd",                 // Grenada
            "ge",                 // Georgia
            "gf",                 // French Guiana
            "gg",                 // Guernsey
            "gh",                 // Ghana
            "gi",                 // Gibraltar
            "gl",                 // Greenland
            "gm",                 // The Gambia
            "gn",                 // Guinea
            "gp",                 // Guadeloupe
            "gq",                 // Equatorial Guinea
            "gr",                 // Greece
            "gs",                 // South Georgia and the South Sandwich Islands
            "gt",                 // Guatemala
            "gu",                 // Guam
            "gw",                 // Guinea-Bissau
            "gy",                 // Guyana
            "hk",                 // Hong Kong
            "hm",                 // Heard Island and McDonald Islands
            "hn",                 // Honduras
            "hr",                 // Croatia (Hrvatska)
            "ht",                 // Haiti
            "hu",                 // Hungary
            "id",                 // Indonesia
            "ie",                 // Ireland (Éire)
            "il",                 // Israel
            "im",                 // Isle of Man
            "in",                 // India
            "io",                 // British Indian Ocean Territory
            "iq",                 // Iraq
            "ir",                 // Iran
            "is",                 // Iceland
            "it",                 // Italy
            "je",                 // Jersey
            "jm",                 // Jamaica
            "jo",                 // Jordan
            "jp",                 // Japan
            "ke",                 // Kenya
            "kg",                 // Kyrgyzstan
            "kh",                 // Cambodia (Khmer)
            "ki",                 // Kiribati
            "km",                 // Comoros
            "kn",                 // Saint Kitts and Nevis
            "kp",                 // North Korea
            "kr",                 // South Korea
            "kw",                 // Kuwait
            "ky",                 // Cayman Islands
            "kz",                 // Kazakhstan
            "la",                 // Laos (currently being marketed as the official domain for Los Angeles)
            "lb",                 // Lebanon
            "lc",                 // Saint Lucia
            "li",                 // Liechtenstein
            "lk",                 // Sri Lanka
            "lr",                 // Liberia
            "ls",                 // Lesotho
            "lt",                 // Lithuania
            "lu",                 // Luxembourg
            "lv",                 // Latvia
            "ly",                 // Libya
            "ma",                 // Morocco
            "mc",                 // Monaco
            "md",                 // Moldova
            "me",                 // Montenegro
            "mg",                 // Madagascar
            "mh",                 // Marshall Islands
            "mk",                 // Republic of Macedonia
            "ml",                 // Mali
            "mm",                 // Myanmar
            "mn",                 // Mongolia
            "mo",                 // Macau
            "mp",                 // Northern Mariana Islands
            "mq",                 // Martinique
            "mr",                 // Mauritania
            "ms",                 // Montserrat
            "mt",                 // Malta
            "mu",                 // Mauritius
            "mv",                 // Maldives
            "mw",                 // Malawi
            "mx",                 // Mexico
            "my",                 // Malaysia
            "mz",                 // Mozambique
            "na",                 // Namibia
            "nc",                 // New Caledonia
            "ne",                 // Niger
            "nf",                 // Norfolk Island
            "ng",                 // Nigeria
            "ni",                 // Nicaragua
            "nl",                 // Netherlands
            "no",                 // Norway
            "np",                 // Nepal
            "nr",                 // Nauru
            "nu",                 // Niue
            "nz",                 // New Zealand
            "om",                 // Oman
            "pa",                 // Panama
            "pe",                 // Peru
            "pf",                 // French Polynesia With Clipperton Island
            "pg",                 // Papua New Guinea
            "ph",                 // Philippines
            "pk",                 // Pakistan
            "pl",                 // Poland
            "pm",                 // Saint-Pierre and Miquelon
            "pn",                 // Pitcairn Islands
            "pr",                 // Puerto Rico
            "ps",                 // Palestinian territories (PA-controlled West Bank and Gaza Strip)
            "pt",                 // Portugal
            "pw",                 // Palau
            "py",                 // Paraguay
            "qa",                 // Qatar
            "re",                 // Réunion
            "ro",                 // Romania
            "rs",                 // Serbia
            "ru",                 // Russia
            "rw",                 // Rwanda
            "sa",                 // Saudi Arabia
            "sb",                 // Solomon Islands
            "sc",                 // Seychelles
            "sd",                 // Sudan
            "se",                 // Sweden
            "sg",                 // Singapore
            "sh",                 // Saint Helena
            "si",                 // Slovenia
            "sj",                 // Svalbard and Jan Mayen Islands Not in use (Norwegian dependencies; see .no)
            "sk",                 // Slovakia
            "sl",                 // Sierra Leone
            "sm",                 // San Marino
            "sn",                 // Senegal
            "so",                 // Somalia
            "sr",                 // Suriname
            "st",                 // São Tomé and Príncipe
            "su",                 // Soviet Union (deprecated)
            "sv",                 // El Salvador
            "sy",                 // Syria
            "sz",                 // Swaziland
            "tc",                 // Turks and Caicos Islands
            "td",                 // Chad
            "tf",                 // French Southern and Antarctic Lands
            "tg",                 // Togo
            "th",                 // Thailand
            "tj",                 // Tajikistan
            "tk",                 // Tokelau
            "tl",                 // East Timor (deprecated old code)
            "tm",                 // Turkmenistan
            "tn",                 // Tunisia
            "to",                 // Tonga
            "tp",                 // East Timor
            "tr",                 // Turkey
            "tt",                 // Trinidad and Tobago
            "tv",                 // Tuvalu
            "tw",                 // Taiwan, Republic of China
            "tz",                 // Tanzania
            "ua",                 // Ukraine
            "ug",                 // Uganda
            "uk",                 // United Kingdom
            "um",                 // United States Minor Outlying Islands
            "us",                 // United States of America
            "uy",                 // Uruguay
            "uz",                 // Uzbekistan
            "va",                 // Vatican City State
            "vc",                 // Saint Vincent and the Grenadines
            "ve",                 // Venezuela
            "vg",                 // British Virgin Islands
            "vi",                 // U.S. Virgin Islands
            "vn",                 // Vietnam
            "vu",                 // Vanuatu
            "wf",                 // Wallis and Futuna
            "ws",                 // Samoa (formerly Western Samoa)
            "ye",                 // Yemen
            "yt",                 // Mayotte
            "yu",                 // Serbia and Montenegro (originally Yugoslavia)
            "za",                 // South Africa
            "zm",                 // Zambia
            "zw",                 // Zimbabwe
    };

    private static final String[] LOCAL_TLDS = new String[]{
            "localhost",           // RFC2606 defined
            "localdomain"          // Also widely used as localhost.localdomain
    };


}

