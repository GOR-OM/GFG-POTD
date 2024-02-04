//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
       int length(Node* head){

        Node* temp=head;

        int count=1;

        while(temp){

            temp=temp->next;

            count++;
        }
        return count;
    }
    void reverse(Node** head){
        Node* cur = *head;
        Node* prev = NULL;
        Node* nextt = NULL;
       
        
        while(cur!=NULL){
           
            nextt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextt;
        }
        *head = prev;
    }
    
    Node* ans(Node* head1,Node* head2){
        reverse(&head1);
        reverse(&head2);
        Node* num = NULL; 
        
  
        int carry=0,flag=0;
        Node* cur1 = head1;Node* cur2 = head2;
        int up,lw,dt;
        while(cur1!=NULL && cur2!=NULL){
          //cout<<"are you hr";
            up = cur1->data;
            lw = cur2->data;
            if(up>=lw && carry==0){
                dt = up-lw;
            }
            else if(up>lw && carry==1){
                dt = up-lw-1;
                carry=0;
            }
            else if(up==lw && carry==0){
                dt = 0;
            }
            else if(up<=lw && carry==1){
                dt = (up+10-1)-lw;
            }
            else if(up<=lw && carry==0){
                dt = (up+10)-lw;
                carry = 1;
            }

            Node* newnum = new Node(dt);
            newnum->next = num;
            num = newnum; 
         
            cur1 = cur1->next;
            cur2 = cur2->next;
           
        }
       //if something left in first list (since it is larger in length)
        while(cur1!=NULL){
            
              if(carry==1){
                  if(cur1->data>0){
                      cur1->data = cur1->data - 1;
                      carry = 0;
                  }
                  else if(cur1->data==0){
                      cur1->data = 9;
                      carry = 1;
                  }
              }
              
              Node* newnum = new Node(cur1->data);
               newnum->next = num;
               num = newnum; 
               cur1 = cur1->next;
        }
        while(num!=NULL && num->data==0){
            num = num->next;
        }
        if(num==NULL){
            Node* ptr = new Node(0);
            return ptr;
        }
        return num;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
     
        while(head1!=NULL && head1->data==0){
            
              head1=head1->next;
        }
        
        while(head2!=NULL && head2->data==0){
           
              head2=head2->next;
        }
      
        if(head1==NULL && head2==NULL){
            Node* ptr = new Node(0);
            return ptr;
        } 
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
       
        int n1 = length(head1);
        int n2 = length(head2);
       
      
        if(n1==n2) {
            while(head1!=NULL && head2!=NULL && head1->data==head2->data){
                head1 = head1->next;
                head2 = head2->next;
            }
            if(head1==NULL || head2==NULL){
                return new Node(0);
            }
            if(head1->data>head2->data){
                return ans(head1,head2);
            }
            else
             return ans(head2,head1);
        }
       
        if(n1>n2){
            return ans(head1,head2);
        }
        else{
            return ans(head2,head1);
        }

        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends