public class UrlGenerator {
	public String  url;
	public Boolean valid;
	
	public int numUnitTests;
	public TestCases tc = new TestCases();
	
	public UrlGenerator() {
		numUnitTests = tc.Protocols.length * 
				       tc.Domains.length * 
				       tc.Paths.length *
				       tc.Ports.length *
				       tc.Query.length;
	}
	
	private int getPermutations(int i) {
		int number = 1;
		for(int k = i; k < 5; k++) {
			number *= tc.Subsets[k].length;
		}
		return number;	
	}
	
    public void unitTestUrl(int target) {
    	int d, q;
		url   = "";
		valid = true;
		for(int k = 0; k < 5; k++) {
			d = getPermutations(k+1);
		    q = target / d;
			url = url.concat(tc.Subsets[k][q].item);
			valid &= tc.Subsets[k][q].valid;
			target = target - d*q;
		}	
    }
}
