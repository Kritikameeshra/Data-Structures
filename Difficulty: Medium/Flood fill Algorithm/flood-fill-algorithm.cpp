//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &image, int color){
        return (x>=0 && y>=0 && x<n && y<m && image[x][y]==color);
        
    }
    
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        if(newColor == image[sr][sc])
            return image;
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            auto z = q.front();
            q.pop();
            
            int tx = z.first;
            int ty = z.second;
            
            for(int k=0;k<4;k++){
                int xx = tx+dx[k];
                int yy = ty+dy[k];
                
                if(isValid(xx, yy, n, m, image, color)){
                    image[xx][yy] = newColor;
                    q.push({xx, yy});
                }
                
            }
            
        }
        
        return image;
                                      
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends