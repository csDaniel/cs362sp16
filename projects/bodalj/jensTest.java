	/**
	 * Testing valid port within authority
	 */
	public void testAuthorityPort() {
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
		
		for (int i = -1000; i < 70000; i++) {
			StringBuilder tempUrl = new StringBuilder();
			tempUrl.append(urlStr);
			tempUrl.append(i);
			expectedResult = i >= minValidPort && i <= maxValidPort ? true: false;
			actualResult = urlVal.isValid(tempUrl.toString());
			if (expectedResult != actualResult) {
				System.out.println(String.format("%s is %b but should be %b", tempUrl.toString(), actualResult, expectedResult ));
			}
		}
	}