//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int,pair<int,int>>>p;
        for(int i=0;i<arr.size();i++){
            p.push_back({abs(arr[i]-brr[i]), {arr[i], brr[i]}});
        }
        sort(p.rbegin(), p.rend());
        
        long long ans=0;
        for(int i=0;i<p.size();i++){
            if(x==0){
                ans+=p[i].second.second;
            }
            else if(y==0){
                ans+=p[i].second.first;
            }
            else{
                if(p[i].second.first > p[i].second.second){
                    x--;
                    ans+=p[i].second.first;
                }
                else{
                    y--;
                    ans+=p[i].second.second;
                }
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends