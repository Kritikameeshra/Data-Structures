//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine();
            String[] S = s1.split(" ");
            String s = S[0];
            String t = S[1];
            Solution ob = new Solution();
            int ans = ob.editDistance(s, t);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


class Solution {

    public int editDistance(String str1, String str2) {
        // Code here
        int m = str1.length();
        int n = str2.length();
        int mat[][] = new int[m+1][n+1];
        
        for(int i =0; i<m+1; i++) {
            mat[i][0] = i;
        }
        
        for(int i =0; i<n+1; i++) {
            mat[0][i] = i;
        }
        
        for(int i=1; i<m+1; i++) {
            for(int j=1; j<n+1; j++) {
                char ch1 = str1.charAt(i-1);
                char ch2 = str2.charAt(j-1);
                if(ch1==ch2) {
                    mat[i][j] = mat[i-1][j-1];
                } else {
                    mat[i][j] = 1 + Math.min(mat[i-1][j-1], Math.min(mat[i-1][j],mat[i][j-1]));
                }
            }
        }
        
        
        return mat[m][n];
    }
}