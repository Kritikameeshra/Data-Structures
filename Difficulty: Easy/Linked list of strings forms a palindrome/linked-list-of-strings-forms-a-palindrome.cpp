//{ Driver Code Starts
// Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str) {
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node *root) {
    Node *temp = root;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


// } Driver Code Ends

class Solution {
  public:
  bool ispalindrome(string str){
      int n=str.length();
      int i=0,j=n-1;
      while(i<j){
          if(str[i] != str[j]) return false;
          else{
              i++;j--;
          }
    }
    return true;
  }
    bool compute(Node* head) {
        // Your code goes here.
        string str="";
        Node*temp = head;
        while(temp != NULL){
            str+=temp->data;
            temp=temp->next;
        }
        // cout<<str;
        return ispalindrome(str);
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            string str = "";
            cin >> str;
            if (head == NULL)
                head = temp = new Node(str);
            else {
                temp->next = new Node(str);
                temp = temp->next;
            }
        }
        Solution ob;
        bool ans = ob.compute(head);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends