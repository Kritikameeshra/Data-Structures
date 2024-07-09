//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        
        int minDiff=INT_MAX; 
        int ans=INT_MIN;
        
        for(int i=0;i<n-2;i++){
            int sum=0;
            int s=i+1;
            int e=n-1;
            while(s<e){
                sum=arr[i]+arr[s]+arr[e];
                
                if(abs(sum-target)<minDiff){//incase of closer element
                    ans=sum;
                    minDiff=abs(sum-target);
                }else if(abs(sum-target)==minDiff){//incase of same difference store the max
                    if(sum>ans)
                        ans=sum;
                }
                    
                if(sum==target)//2 pointer approach to find two sum
                    return sum;
                else if(sum<target)
                    s++;
                else
                    e--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends