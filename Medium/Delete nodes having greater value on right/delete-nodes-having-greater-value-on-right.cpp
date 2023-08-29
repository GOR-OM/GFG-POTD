//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

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
class Solution
{
    public:
    Node *compute(Node *head)
    {   
        if(!head->next) return head;
        Node* dum = new Node(0);
        dum->next = head;
        Node* t1 = head;
        Node* t2 = dum;
        Node* t3 = t1->next;
        while(t1->next){
            while(t3 && t1->data >= t3->data){
                t3 = t3->next;
            }
            if(t3 && t1->data < t3->data){
                t2->next = t1->next;
                t1 = t1->next;
            }else{
                t2 = t2->next;
                t1 = t1->next;
                if(t1->next) t3 = t1->next;
                else break;
            }
        }
        return dum->next;
    }

    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends