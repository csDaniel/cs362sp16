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

import java.util.Random;

import java.security.SecureRandom;
import java.math.BigInteger;


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


    public void testManualTest() {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
    }


    public void testPortPartition() {
        System.out.println("*** TEST PORT ***");
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String[] inputs = {
                "http://www.google.com:8",
                "http://www.google.com:80",
                "http://www.google.com:800",
                "http://www.google.com:8000",
                "http://www.google.com:80000",
                "http://www.google.com:",
                "http://www.google.com:x",
                "http://www.google.com:80x",
                "http://www.google.com:-20",
                "http://www.google.com:65535",
                "http://www.google.com:65536"
        };
        for (int i = 0; i < inputs.length; i++) {
            System.out.println("TEST\t" + inputs[i] + " ... " + urlVal.isValid(inputs[i]));
        }

    }

    public void testPathPartition() {
        System.out.println("*** TEST PATH ***");
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String[] inputs = {
                "http://www.google.com/path",
                "http://www.google.com/123",
                "http://www.google.com/!",
                "http://www.google.com//",
                "http://www.google.com/.",
                "http://www.google.com/..",
                "http://www.google.com/../",
                "http://www.google.com/path/../",
                "http://www.google.com/../path",
                "http://www.google.com/path//file",
                "http://www.google.com/path-dash",
                "http://www.google.com/path_underscore",
                "http://www.google.com/path space/",
        };
        for (int i = 0; i < inputs.length; i++) {
            System.out.println("TEST\t" + inputs[i] + " ... " + urlVal.isValid(inputs[i]));
        }
    }

    public void testRandomPorts() {
        Random randomGenerator = new Random();
        int valid = 0;
        int invalid = 0;
        System.out.println("*** TEST PORT (RANDOM) ***");
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        for (int i = 0; i < 10000; i++) {
            int randomPortValue = randomGenerator.nextInt((65535 - (-65535)) + 1) + (-65535);
            boolean testIsValid = urlVal.isValid("http://www.google.com:" + randomPortValue);
            System.out.println("TEST\t" + "http://www.google.com:" + randomPortValue + " ... " + testIsValid);
            if (testIsValid) {
                valid++;
            } else {
                invalid++;
            }
        }
        System.out.println("Tested 10000 random port values");
        System.out.println("PASSED: " + valid);
        System.out.println("FAILED: " + invalid);
    }

    public void testRandomPath() {
        SecureRandom random = new SecureRandom();
        int valid = 0;
        int invalid = 0;
        System.out.println("*** TEST PATH (RANDOM) ***");
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        for (int i = 0; i < 10000; i++) {
            String base = "http://www.google.com";
            int numberOfPaths = random.nextInt(10);
            for (int p = 0; p < numberOfPaths; p++) {
                int pathLength = random.nextInt(10);
                String frag = randomString(pathLength);
                base = base + "/" + frag;
            }
            boolean testIsValid = urlVal.isValid(base);
            System.out.println("TEST\t" + base + " ... " + testIsValid);
            if (testIsValid) {
                valid++;
            } else {
                invalid++;
            }
        }
        System.out.println("Tested 10000 random path values");
        System.out.println("PASSED: " + valid);
        System.out.println("FAILED: " + invalid);
    }


    // http://stackoverflow.com/questions/18069434/generating-alphanumeric-random-string-in-java
    public static String randomString(int length) {
        char[] CHARSET_AZ_09 = "!@#$%^&*()_+-=[];'/.,abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789".toCharArray();
        Random random = new SecureRandom();
        char[] result = new char[length];
        for (int i = 0; i < result.length; i++) {
            // picks a random index out of character set > random character
            int randomCharIndex = random.nextInt(CHARSET_AZ_09.length);
            result[i] = CHARSET_AZ_09[randomCharIndex];
        }
        return new String(result);
    }
}