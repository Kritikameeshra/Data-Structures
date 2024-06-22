//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    public:
    
    bool isNum(char n)
    {
        if(n == '0' || n == '1' || n == '2' || n == '3' || n == '4' || n == '5' || n == '6' || n == '7' || n == '8' || n == '9')
            return true ;
            
        return false ;
    }
    
    long long ExtractNumber(string sentence) {
        
        long long largest = -1 , num = 0 ;
        int i = 0 , n = sentence.size() ;
        bool contain9 = false , gotNum = false ;
        
        while(i < n)
        {
            while(i < n && !isNum(sentence[i]))
                ++i ;
                
            while(i < n && isNum(sentence[i]))
            {
                num = num * 10 + (sentence[i] - '0') ;
                if(sentence[i] - '0' == 9)
                    contain9 = true ;
                gotNum = true ;
                ++i ;
            }
            
            if(!contain9 && gotNum)
                largest = max(largest , num) ;
                
            contain9 = false ;
            gotNum = false ;
            num = 0 ;
        }
        
        return largest ;
        
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends