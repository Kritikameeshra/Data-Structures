//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int x[] = new int[str.length];
            for (int i = 0; i < str.length; i++) x[i] = Integer.parseInt(str[i]);
            str = (br.readLine()).trim().split(" ");
            int[] y = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                y[i] = Integer.parseInt(str[i]);
            }
            System.out.println(new Solution().countPairs(x, y, x.length, y.length));
        }
    }
}

// } Driver Code Ends


//Back-end complete function Template for Java
class Solution {

    public long countPairs(int x[], int y[], int m, int n) {
        
        int suffix[]=new int[1002];
        long ans=0;
        for(int i=0;i<n;i++){
            suffix[y[i]]++;
        }
        
        for(int i=1000;i>=3;i--){
            suffix[i]=suffix[i]+suffix[i+1];
        }
        
        for(int i=0;i<m;i++){
            if(x[i]==1){
                continue;
            }
            else if(x[i]==2){
                ans+=suffix[1]+suffix[5];
            }
            else if(x[i]==3){
                 ans+=suffix[1]+suffix[2]+suffix[4];  
            }
            else{
                ans+=suffix[1]+suffix[x[i]+1];
            }
        }
        
        
      return ans; 
    }
}