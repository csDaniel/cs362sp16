public class TestCases {
	
	 public ResultPair[] manualTests = 
		  {  new ResultPair("http://x.y.z.com", true),
			 new ResultPair("3ttp://x.y.z.com", false),
			 new ResultPair("http://x.y.z.com/", true),
			 new ResultPair("http://x.y.z.???/", false),
			 new ResultPair("http://x.y.z.com:80", true),
			 new ResultPair("http://x.y.z.com:1000000", false),
			 new ResultPair("http://x.y.z.com/p1", true),
			 new ResultPair("http://x.y.z.com/p..1", false),
			 new ResultPair("http://x.y.z.com/p?a=1", true),
			 new ResultPair("http://x.y.z.com/p?\n", false) };

	 public ResultPair[] schemeTests = 
		  {  new ResultPair("ftp://www.google.com", true),
			 new ResultPair("https://www.google.com", true),
			 new ResultPair("://www.google.com", false),
			 new ResultPair("", false),
			 new ResultPair("http://", false),
			 new ResultPair("134http://", false),
			 new ResultPair("http:// www.google.com", false),
			 new ResultPair("http%://www.google.com", false) };
	 
	 public ResultPair[] authorityTests =
		  {  new ResultPair("http://x.y.z.com:100000", false),
			 new ResultPair("http://x.y.z.com:65535", true),
			 new ResultPair("http://x.y.z.com:10000", true),
			 new ResultPair("http://x.y.z.com:1000",  true),		 
			 new ResultPair("http://x.y.z.com:100", true),
			 new ResultPair("http://x.y.z.com:10", true),
			 new ResultPair("http://x.y.z.com:1", true),
			 new ResultPair("http://x.y.z.com:0", true),
			 new ResultPair("http://x.y.z.com:-1", false),
			 new ResultPair("http://-1.-1.-1.-1", false),
			 new ResultPair("http://0.0.0.0", true),
			 new ResultPair("http://52.52.52.52", true),
			 new ResultPair("http://255.255.255.255", true),
			 new ResultPair("http://256.256.256.256",  false),		 
			 new ResultPair("http://1256.1256.1256.1256", false),
			 new ResultPair("http://152.52.152.52:80",  true),			 
			 new ResultPair("http://www..google.com", false),
			 new ResultPair("http://52.52.52", false) 
			 };

	 public ResultPair[] pathTests =
		  {  new ResultPair("http://www.google.com/path1", true),
			 new ResultPair("http://www.google.com:80/path1/path2", true),
			 new ResultPair("http://52.52.52.52/path1/", true),		 
			 new ResultPair("http://152.52.152.52:80/path1/path2/", true),
			 new ResultPair("http://www.google.com//path1", false),
			 new ResultPair("http://www.google.com:\\path1",  false),	
			 new ResultPair("http://www.google.com/ path1",  false) };
	 
	 public ResultPair[] queryTests =
		  {  new ResultPair("http://www.google.com/path1?parm1=1&parm2=2", true),
			 new ResultPair("http://www.google.com:80/?parm1=1", true),
			 new ResultPair("http://www.googl2.com?parm1=1", true),		 
			 new ResultPair("http://www.google.com/path1?\n", false) };
	 
	
/*************************************************************************
                          URL Subsets
*************************************************************************/                                                        	
	
	public ResultPair[] Protocols = 
		  { new ResultPair("http://", true), 
		    new ResultPair("ftp://", true),
	    	new ResultPair("https://", true),
			new ResultPair("://", false),
			new ResultPair("", false),
			new ResultPair("134http://", false),
			new ResultPair("http%://", false) };

	public ResultPair[] Domains   = 
		  { new ResultPair("", false),
		    new ResultPair("-1.-1.-1.-1", false),
			new ResultPair("0.0.0.0", true),
			new ResultPair("52.52.52.52", true),
			new ResultPair("255.255.255.255", true),
			new ResultPair("256.256.256.256",  false),		 
		    new ResultPair("1256.1256.1256.1256", false),
		    new ResultPair("152.52.152.52",  true),			 
			new ResultPair("http://www..google.com", false),
		    new ResultPair("http://52.52.52", false),	
		    new ResultPair(".www.foo.bar", false),
	        new ResultPair("www.foo.bar.", false),
	        new ResultPair(" www.foo.bar", false),
	        new ResultPair("www-.foo-bar", false),
            new ResultPair("1.2.3.4.5", false),
            new ResultPair("1.2.3", false),
	        new ResultPair("36323457", false),
	        new ResultPair("a.1.-a.1", false),      
	        new ResultPair("www.google.com", true),
            new ResultPair("go.com", true),
            new ResultPair("1337.net", true),
            new ResultPair("go.au", true),
            new ResultPair("a.b-c.de", true),
            new ResultPair("142.42.1.1", true),
            new ResultPair("255.com", true),
            new ResultPair("go.cc", true)  }; 
	
	public ResultPair[] Ports     = 
		  { new ResultPair(":100000", false),
		    new ResultPair(":65535", true),
			new ResultPair(":10000", true),
			new ResultPair(":1000",  true),		 
			new ResultPair(":100", true),
		    new ResultPair(":10", true),
		    new ResultPair(":1", true),
			new ResultPair(":0", true),
			new ResultPair(":-1", false) };
	 
	public ResultPair[] Paths     =
		  { new ResultPair("", true),
		    new ResultPair("/path1/", true),
		    new ResultPair("/path1", true),
            new ResultPair("/path/t123/", true),           
			new ResultPair(" /path1",  true),        
            new ResultPair("//path", false) };  
	
 	public ResultPair[] Query     = 
 		  { new ResultPair("?gws_rd=ssl", true),
 			new ResultPair("?gws_rd=ssl&t1=1", true),
            new ResultPair("action= 1 and 2", false),
            new ResultPair("", true) };   
 	
 	 
 	public ResultPair[][] Subsets  = { Protocols, Domains, Ports, Paths, Query };

}