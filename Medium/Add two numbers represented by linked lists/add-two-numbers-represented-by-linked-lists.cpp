//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     Node* func(Node* num1, Node* num2, int c){
        if(!num1 and !num2) return new Node(c); 
        int sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + c;
        Node* nn = new Node(sum % 10); 
        nn->next = func((num1 ? num1->next : num1), (num2 ? num2->next : num2), sum / 10);
        return nn;
    }
    
    // Reversing_Linked_List
    Node* rev(Node* head){
        Node* tmp = NULL, *prev = NULL, *curr = head;
        while(curr) tmp = curr->next, curr->next = prev, prev = curr, curr = tmp;
        return prev;
    }
    // Remove_Leading_Zeros
    Node* rz(Node* head){
        while(head and head->data == 0) head = head->next;
        return head == NULL ? new Node(0) : head;
    }
    
    // Main Function
    struct Node* addTwoLists(struct Node* num1, struct Node* num2){   
        return rz(rev(func(rev(rz(num1)), rev(rz(num2)), 0))); 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends