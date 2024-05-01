//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends

class Solution {
  public:
    bool isV(char c){
        string s="aeiou";
        return s.find(c) != string::npos;
    }
    struct Node* arrangeCV(Node* head) {
        Node*f=NULL,*t=head,*p=NULL;
        if(isV(head->data)){
            f=head;t=t->next;p=f;
        } 
        while(t){
            if(isV(t->data)){
                Node*next=t->next;
                    if(!f){
                        f=t;
                        f->next=head;
                        head=f;
                    } 
                    else if(f->next==t){
                        f=f->next;p=f;t=t->next;continue;
                    }
                    else { 
                        Node*tmp=f->next;
                        f->next=t;
                        t->next=tmp;
                        f=f->next;
                    }
                    p->next=next;
                    t=next;
            }
            else{
                p=t;
                t=t->next;
            }
        }
        return head;
    }
};




//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends