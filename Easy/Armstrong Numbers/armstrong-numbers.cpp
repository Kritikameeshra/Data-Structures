//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:

    string armstrongNumber(int n) {

        // code here

        int x=n;

        int sum=0;

        while(x!=0){

            int y=x%10;

            sum =sum +(y*y*y);

            x=x/10;

        }

        if(sum==n){

            return string("true");

        }

        else{

            return string("false");

   

    }

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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends