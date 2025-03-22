//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&arr,int idx,bool& first,vector<int>& dp){
        if(arr.size()<=idx){
            return 0;
        }
        if(first && idx==arr.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int include = arr[idx]+solve(arr,idx+2,first,dp);
        int noinclude = solve(arr,idx+1,first,dp);
        return dp[idx] = max(include,noinclude);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        vector<int>dp1(arr.size()+1,-1);
        bool first = true;
        int take = arr[0]+solve(arr,2,first,dp1);
        first = false;
        vector<int>dp2(arr.size()+1,-1);
        int notake = solve(arr,1,first,dp2);
        return max(take,notake);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends