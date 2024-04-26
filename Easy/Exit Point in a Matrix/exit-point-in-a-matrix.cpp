//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
       vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}}; //4 directions
       int i=0,j=0,direction_ptr=0;
       vector<int>res;
       while(i>=0 and i<n and  j>=0 and j<m){  //i and j within matrix bounds
          if(matrix[i][j]==1){
              direction_ptr=(direction_ptr+1)%4; 
              matrix[i][j]=0;
          }
           res={i,j}; //keep last valid i and j
           i=i+directions[direction_ptr][0];
           j=j+directions[direction_ptr][1];
       }
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends