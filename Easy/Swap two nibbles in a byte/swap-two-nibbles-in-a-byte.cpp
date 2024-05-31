//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int swapNibbles(int n) {
        int ans = 0;
        for(int i = 0; i < 8; i++) {
            if((n&1) == 1) {
                if(i < 4)
                    ans = ans + (1 << (4 + i));
                else 
                    ans = ans + (1 << (i - 4));
            }
            n = n >> 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends