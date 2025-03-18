//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& prashantArr, int mishraSum) {
    int prashantSize = prashantArr.size();
    vector<vector<int>> prashantDP(prashantSize + 1, vector<int>(mishraSum + 1, 0));

    for (int Mishra_i = 0; Mishra_i < prashantSize + 1; Mishra_i++) {
        for (int PRASHANT_J = 0; PRASHANT_J < mishraSum + 1; PRASHANT_J++) {
            if (PRASHANT_J == 0) {
                prashantDP[Mishra_i][PRASHANT_J] = 1;
            } 
            else if (Mishra_i != 0 && PRASHANT_J >= prashantArr[Mishra_i - 1]) {
                prashantDP[Mishra_i][PRASHANT_J] = (prashantDP[Mishra_i - 1][PRASHANT_J] | prashantDP[Mishra_i - 1][PRASHANT_J - prashantArr[Mishra_i - 1]]);
            } 
            else if (Mishra_i != 0) {
                prashantDP[Mishra_i][PRASHANT_J] = prashantDP[Mishra_i - 1][PRASHANT_J];
            }
        }
    }
    return prashantDP[prashantSize][mishraSum];
}

bool equalPartition(vector<int>& Prashant_Array) {
    int MISHRA_SUM = 0;
    
    for (int mishraIndex = 0; mishraIndex < Prashant_Array.size(); mishraIndex++) {
        MISHRA_SUM += Prashant_Array[mishraIndex];
    }

    if ((MISHRA_SUM & 1)) {
        return false;
    }

    return solve(Prashant_Array, MISHRA_SUM / 2);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends