//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    bool isVowel(char data){
        return( data=='a')|| (data=='e') || (data=='i') || (data=='o') || (data=='u');
    }
    void *insertAtEndLL(Node *&head,Node *&tail,int data){
        if(head==NULL){
            Node *newNode=new Node(data);
            head=newNode;
            tail=newNode;
            
        }
        else{
            Node *newNode=new Node(data);
            tail->next=newNode;
            tail=newNode;
        }
    }
    struct Node* arrangeCV(Node *head)
    {
       vector<char>vow;
       vector<char>consonanats;
       while(head!=NULL){
           if(isVowel(head->data)){
               vow.push_back(head->data);
           }
           else{
               consonanats.push_back(head->data);
           }
           head=head->next;
       }
       
    //   create a LL using Vowels first
    Node *vishalHead=NULL,*VishalTail=NULL;
    for(auto c:vow){
        insertAtEndLL(vishalHead,VishalTail,c);
        
        
    }
    for(auto c:consonanats){
        insertAtEndLL(vishalHead,VishalTail,c);
    }
    return vishalHead;
    
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends