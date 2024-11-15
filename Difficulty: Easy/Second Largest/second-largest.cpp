//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++



class Solution {

  public:

    int getSecondLargest(vector<int> &arr) {

        int n=arr.size();

        sort(arr.begin(),arr.end());

        //size represented last and largest num of array

        int size=n-1;

        while(size>0){

        //conditions check if the second largest is not the duplicate of first largest 

            if(arr[size]!=arr[size-1]){

                return arr[size-1];

            }

        //if it's a duplicate, skip that element by iterating size

        size--;

        }

        return -1;

        //arr[size]--》largest element

        //arr[size-1]--》second largest more like arr[n-2]

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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends