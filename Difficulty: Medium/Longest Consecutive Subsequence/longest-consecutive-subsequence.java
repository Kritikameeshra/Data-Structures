//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            // Read first array
            String input = br.readLine();
            String[] inputArray = input.split(" ");
            int[] arr = Arrays.stream(inputArray).mapToInt(Integer::parseInt).toArray();

            Solution ob = new Solution();
            int res = ob.longestConsecutive(arr);

            System.out.println(res);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {

    // Function to return length of longest subsequence of consecutive integers.
    public int longestConsecutive(int[] arr) {
        // code here
        HashSet<Integer> hashSet = new HashSet<>();
        for(int el: arr) {
            hashSet.add(el);
        }
        int best = 0;
        for(int i = 0; i < arr.length; i++) {
            if(!hashSet.contains(arr[i]-1)) {
                int j = arr[i] + 1;
                while(hashSet.contains(j)) {
                    j += 1;
                }
                best = Math.max(best, j-arr[i]);
            }
            
        }
        return best;
        
    }
}