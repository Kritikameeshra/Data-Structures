//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* head = new Node(0);
        Node* ptr = head;
        Node* curr = NULL;
        while(1){
            int pos  = -1;
            for(int i=0;i<arr.size();i++){
                if(curr==NULL && arr[i]){
                    curr = arr[i];
                    pos = i;
                }
                else if(curr && arr[i]){
                    if(curr->data>arr[i]->data){
                        curr = arr[i];
                        pos = i;
                    }
                }
            }
            if(pos == -1 && curr == NULL)break;
            if(curr){
                ptr->next = curr;
                ptr = ptr->next;
                arr[pos] = arr[pos]->next;
                curr = NULL;
            }
        }
        return head->next;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends