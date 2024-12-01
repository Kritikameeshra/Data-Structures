//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
     char nonRepeatingChar(string &s) 
    {
        unordered_map<char,int> mp;
        char ans='$';
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i] -  'a']++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i] -  'a'] == 1)
                return s[i];
        }
        return ans;
        // Your code here
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends