//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Custom comparison function for sorting.
    static bool condition(pair<int,int>& p1, pair<int,int>& p2) {
        // If frequencies are the same, compare elements
        return (p1.second == p2.second) ? p1.first < p2.first : p1.second > p2.second;
    }

    // Function to sort the array according to the frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        map<int,int> mp;

        // Step 1: Calculate frequency of each element.
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        // Step 2: Store elements and their frequencies as pairs in a vector.
        vector<pair<int,int>> p(mp.begin(), mp.end());

        // Step 3: Sort the vector based on frequency and then value.
        sort(p.begin(), p.end(), condition);

        // Step 4: Generate the sorted array.
        vector<int> ans;
        for(pair<int,int>& temp : p) {
            while(temp.second--) {
                ans.push_back(temp.first);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends