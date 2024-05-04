//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

     int position(int in[], int inStart, int inEnd, int val){
        for(int i=inStart; i<=inEnd; i++){
            if(in[i]==val)
            return i;
        }
        return -1;
    }
    Node *tree(int in[], int post[], int &postind, int inStart, int inEnd){
        if(postind<0 || inStart>inEnd)
        return NULL;
        
        int val=post[postind--];
        Node *node=new Node(val);
        
        int pos=position(in, inStart, inEnd, val);
        
        node->right=tree(in, post, postind, pos+1, inEnd);
        node->left=tree(in, post, postind, inStart, pos-1);
        
        return node;
        
        
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postind=n-1;
        Node *ans=tree(in, post, postind, 0, n-1);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends