//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
	    
	    //taking input using Scanner class
		Scanner sc=new Scanner(System.in);
		
		//taking total testcases
		int t=sc.nextInt();
		sc.nextLine();
		while(t-->0)
		{
		    //taking the String
		    String s=sc.nextLine();
		    Solution ob = new Solution();
		    //calling method sumSubstrings() 
		    System.out.println(ob.sumSubstrings(s));
		}
	}
}
// } Driver Code Ends


class Solution
{
    public static long sumSubstrings(String s)
    {
        int modulo = 1000000007;
        int n = s.length();
        long result = 0;
        long multiplier = 1; 
        for (int i = n - 1; i >= 0; i--) {
            int digit = s.charAt(i) - '0'; 
            result = (result + (digit * multiplier * (i + 1)) % modulo) % modulo;
            multiplier = (multiplier * 10 + 1) % modulo; 
        }
        return result;
    }
}