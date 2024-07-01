//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
int Floor(Node* root, int key, int ans) {
    if (root == NULL) return ans;
    if (root->data == key) return root->data;

    if (root->data < key && root->data > ans) {
        return Floor(root->right, key, root->data);
    }
    if (root->data > key) {
        return Floor(root->left, key, ans);
    }
    return ans;
}

    
    int floor(Node* root, int x) {
       
       int ans =  Floor(root,x, INT_MIN);
       return ans==INT_MIN ? -1 : ans;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends