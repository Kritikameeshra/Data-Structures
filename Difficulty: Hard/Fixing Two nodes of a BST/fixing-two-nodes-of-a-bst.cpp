//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper) {
    if (!n)
        return true;
    if (n->data <= lower || n->data >= upper)
        return false;
    return (isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper));
}

bool compare(Node* a, Node* b, vector<pair<int, int>>& mismatch) {
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;

    if (a->data != b->data)
        mismatch.push_back(pair<int, int>(a->data, b->data));

    return (compare(a->left, b->left, mismatch) &&
            compare(a->right, b->right, mismatch));
}


// } Driver Code Ends
/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  // Vector to store pairs of node values and the corresponding node pointers
  vector<pair<int , Node*>> ino;

  // Helper function to perform inorder traversal and store nodes in the vector 'ino'
  void func(Node* root){
      // Base case: if the current node is NULL, return
      if(root==NULL) return;
      
      // Recursively traverse the left subtree
      if(root->left){
          func(root->left);
      }
      
      // Store the node's data and its pointer as a pair in the 'ino' vector
      ino.push_back({root->data , root});
      
      // Recursively traverse the right subtree
      if(root->right){
          func(root->right);
      }
  }

  // Function to fix the BST by swapping the two misplaced nodes
  void correctBST(Node* root) {
      // Perform inorder traversal and fill 'ino' with the node values and pointers
      func(root);
      
      // Create a new vector 'so' which is a copy of 'ino'
      vector<pair<int , Node*>> so;
      so = ino;

      // Sort the 'so' vector based on the node values (ascending order)
      sort(so.begin(), so.end());

      // Node pointer to store the first misplaced node
      Node* no = NULL;

      // Iterate through the 'ino' vector and compare it with the sorted 'so' vector
      for(int i=0; i<ino.size(); i++){
          // Check if the node values at the current position are not equal
          if(ino[i].first != so[i].first && no == NULL){
              // The first misplaced node is found; store it in 'no'
              no = ino[i].second;
          }
          // If a mismatch is found and 'no' is already set, swap the node values
          else if(ino[i].first != so[i].first){
             // Swap the values of the 'no' node and the current node in 'ino'
             swap(no->data , ino[i].second->data);
          }
      }
  }   
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        // check 1: is tree now a BST
        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if (!compare(root, duplicate, mismatch)) {
            // false output from this function indicates change in structure of tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if (mismatch.size() != 2 || mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first)
            cout << "0\n";
        else
            cout << "1\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends