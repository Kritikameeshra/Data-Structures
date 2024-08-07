//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0; i<arr1.size(); i++){
            pq.push(arr1[i]);
        }
        for(int i=0; i<arr2.size(); i++){
            pq.push(arr2[i]);
        }
        for(int i=1; i<=k; i++){
            if(i==k){
                return pq.top();
            }
            else{
                pq.pop();
            }
        }
    }
};



//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends