//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> stockspan( vector<int>&arr){
      stack<pair<int,int>>st;
      vector<int>ans(arr.size(),1);
      st.push({arr[arr.size()-1],arr.size()-1});
      for(int i=arr.size()-2;i>=0;i--){
          if(arr[i]<st.top().first){
            while(!st.empty()&&arr[i]<st.top().first){
              ans[st.top().second]=st.top().second-i;
              st.pop();
            }
            st.push({arr[i],i});
          }
          else{
              st.push({arr[i],i});
          }
      }
      while(!st.empty()&&st.top().first>INT_MIN){
          ans[st.top().second]=st.top().second-(-1);
              st.pop();
      }
      
      
      return ans;
    }
    vector<int> stockspanafter(vector<int>&arr){
        stack<pair<int,int>>st;
      vector<int>ans(arr.size(),1);
      st.push({arr[0],0});
      for(int i=1;i<arr.size();i++){
          if(arr[i]<st.top().first){
            while(!st.empty()&&arr[i]<st.top().first){
              ans[st.top().second]=i-st.top().second;
              st.pop();
            }
            st.push({arr[i],i});
          }
          else{
              st.push({arr[i],i});
          }
      }
      while(!st.empty()&&st.top().first>INT_MIN){
          ans[st.top().second]=arr.size()-st.top().second;
              st.pop();
      }
      
      
      return ans;
        
    }
    int getMaxArea(vector<int> &arr) {
        // just similar to the  stock span problem (before+after both cases here )
        //basically current height ka maximum rectangle  bna lo  usk lie stock span k concept ka use kia (element k after and before)
       
        int ans = INT_MIN;
        
        int tempans=0;
        vector<int>greaterbuildings_before=stockspan(arr);
        vector<int>greaterbuildings_after=stockspanafter( arr);
        for(int i = 0 ;i<arr.size();i++){
                
        
            
             tempans=(greaterbuildings_before[i]+greaterbuildings_after[i]-1)*arr[i];
            
             ans=max({ans,tempans});
            
        }
        
        return ans ;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends