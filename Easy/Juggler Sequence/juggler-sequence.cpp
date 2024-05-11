//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      vector<long long> jugglerSequence(long long n) 
      {
        vector<long long> res;
        stack<long long> s;
        res.push_back(n);
        s.push(n);

        while (!s.empty()) 
        {
            long long current = s.top();
            long long next = 0;

            if (current == 1) 
            {
                break;
            }

            if (current % 2 == 0) 
            {
                next = static_cast<long long>(pow(current, 0.5));
            } 
            else 
            {
                next = static_cast<long long>(pow(current, 1.5));
            }

            res.push_back(next);
            s.push(next);
        }

        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends