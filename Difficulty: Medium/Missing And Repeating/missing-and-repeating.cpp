//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int repeating = -1;
        int missing = -1;
        
        for(int i = 0; i < n; ++i){
            int index = abs(arr[i]) -1;
            if(arr[index] < 0){
                repeating = abs(arr[i]);
            }else{
                arr[index] = -arr[index];
            }
        }
        
        for(int i=0; i<n; ++i){
            if(arr[i] > 0){
                missing = i + 1;
                break;
            }
        }
        return {repeating, missing};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends