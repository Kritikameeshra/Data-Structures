//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            List<Integer> nums = new ArrayList<>();
            for (String part : parts) {
                nums.add(Integer.parseInt(part));
            }
            Solution ob = new Solution();
            List<Integer> ans = ob.findMajority(nums);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    public List<Integer> findMajority(List<Integer> nums) {
        int n = nums.size();
        
        if (n == 0) return Arrays.asList(-1);
        
        // Step 1: Candidate selection using Boyer-Moore Voting Algorithm
        Integer candidate1 = null, candidate2 = null;
        int count1 = 0, count2 = 0;
        
        for (int num : nums) {
            if (candidate1 != null && candidate1 == num) {
                count1++;
            } else if (candidate2 != null && candidate2 == num) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Step 2: Validate the candidates
        count1 = 0;
        count2 = 0;
        
        for (int num : nums) {
            if (candidate1 != null && num == candidate1) count1++;
            if (candidate2 != null && num == candidate2) count2++;
        }
        
        List<Integer> result = new ArrayList<>();
        if (count1 > n / 3) result.add(candidate1);
        if (count2 > n / 3 && !Objects.equals(candidate1, candidate2)) result.add(candidate2);
        
        // Step 3: Sort the result in increasing order
        Collections.sort(result);
        
        // Step 4: Return result or -1 if no majority element is found
        return result.isEmpty() ? Arrays.asList(-1) : result;
    }
}