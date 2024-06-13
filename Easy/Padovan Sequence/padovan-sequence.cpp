//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        int p[n+1];
        p[0]=1;
        p[1] = 1;
        p[2] = 1;
        int i=3;
        if(n<3){
            return 1;
        }
        while(i<=n){
            p[i] = p[i-2]%(1000000000+7) + p[i-3]%(1000000000+7);
            i++;
        }
        
        return p[n]%(1000000000+7);

 

//for the recursive one though it's not necessary here
    //   if(n==0 || n==1 || n==2){
    //       return 1;
    //   }
    //   return padovanSequence(n-2)+padovanSequence(n-3);
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends