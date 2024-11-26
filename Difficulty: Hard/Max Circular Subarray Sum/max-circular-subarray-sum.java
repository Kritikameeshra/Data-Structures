//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().circularSubarraySum(arr));
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {

    // a: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    public int circularSubarraySum(int arr[]) {

         int n=arr.length;
       int totalsum=0;
       int maxsofar=0;
       int minsofar=0;
       int maxsum=Integer.MIN_VALUE;
       int minsum=Integer.MAX_VALUE;
       for(int num:arr){
           totalsum+=num;
           maxsofar+=num;
           minsofar+=num;
           maxsum=Math.max(maxsofar,maxsum);
           minsum=Math.min(minsofar,minsum);
           if(maxsofar<0){
               maxsofar=0;
           }
           if(minsofar>0){
               minsofar=0;
           }
           
       }
       return Math.max(totalsum-minsum,maxsum);
    }
}
