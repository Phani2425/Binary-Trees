//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to delete a node from BST.
Node *deleteNode(Node *root, int target) {
    // base case
    if(!root){
        return NULL;
    }
    
    if(root->data > target){
        root->left = deleteNode(root->left,target);
    }
    
    else if(root->data < target){
        root->right = deleteNode(root->right, target);
    }
    
    else{//if root ra value target saha saman and we are on the target now
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if(!root->left){ //root have only right child
            Node * temp = root->right;
            delete root;
            return temp;
        }   
        else if(!root->right){//root have only left child
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else{ //root have both child
            Node * child = root->left;
            Node * parent = root;
            while(child->right){
                parent=child;
                child=child->right;
            }
            if(parent == root){//edge case where parent is the target node itself(explained in detail in notes)
                child->right = root->right;
                delete root;
                return child;
            }
            else{//here we will handle another edge case jouthi :- tarrget node ra left subtree ra rightmmost node ra left child thhibara possiblity achi
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                return child;
            }
        }
        
        return root;
    }
}
