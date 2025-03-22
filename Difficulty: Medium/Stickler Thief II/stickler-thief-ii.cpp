//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&arr,int i,vector<int>&dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0,nottake=0;
        take=arr[i]+solve(arr,i+2,dp);
        nottake=solve(arr,i+1,dp);
        return dp[i]=max(take,nottake);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int second=solve(arr,1,dp);
        arr.pop_back();
        dp=vector<int>(n,-1);
        int first=solve(arr,0,dp);
        return max(first,second);
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