//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // This is a greedy algo
    // Keep connecting the houses from minimum to maximum without redundancies
    // Redundancy is for example 1->2->3->4 is there and 5->6 is there
    // Now connecting 3 to 6 makes sense because all the houses should be connected
    // But connecting 4 to 2 doesnt make any sense becase they are all already connected
    // So keep connecting the houses from minimum cost to maximum cost without redundancies
    // Logic:
    // Find distances of all houses and store distances and houses in a vector
    // Sort the distances
    // Keep adding the edges between the houses based on the sorted distances
    // If adding an edge is redundant dont add it
    // You can know if adding an edge is redundant or not by disjoint set union
    int findUltimateParent(vector<int>& parent, int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent, parent[node]);
    }
    void dsu(vector<int>& parent, vector<int>& size, int u, int v)
    {
        int ulp_u = findUltimateParent(parent, u);
        int ulp_v = findUltimateParent(parent, v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        vector<int> size(n, 1);
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int dist = abs(houses[i][0]-houses[j][0]) + abs(houses[i][1]-houses[j][1]);
                edges.push_back({i, j, dist});
            }
        }
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[2] < b[2];
        });
        int ans = 0;
        for(vector<int>& i: edges)
        {
            if(findUltimateParent(parent, i[0]) != findUltimateParent(parent, i[1]))
            {
                ans += i[2];
                dsu(parent, size, i[0], i[1]);
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
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends