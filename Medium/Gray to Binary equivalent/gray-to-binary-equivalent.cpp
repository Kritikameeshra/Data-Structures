//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    string toBinary(int num)
    {
        string str;
          while(num){
          if(num & 1) 
            str+='1';
          else 
            str+='0';
          num>>=1;  
        }    
          return str;
    }
    int toDecimal(string binary) {
        int dec_value = 0;
        int base = 1;
        
        for (int i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1')
                dec_value += base;
            base *= 2;
        }
        
        return dec_value;
    }
    
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        string str = toBinary(n);
        reverse(str.begin() , str.end());
        
        string ans = "";
        ans += str[0];
        for(int i = 1 ; i < str.size() ; i++){
            ans += to_string((ans[i-1]-'0')^(str[i]-'0'));
        }
        
        return toDecimal(ans);
    }
};



//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends