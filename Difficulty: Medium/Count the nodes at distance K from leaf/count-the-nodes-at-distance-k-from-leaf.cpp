//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    unordered_set<Node*> nodes;
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	vector<Node*>path;
    	checkPath(root,path,k);
    	
    	return nodes.size();
    }
    
    private:
    
    void checkPath(Node* root, vector<Node*>& path,int&k){
        if(!root) return;
        
        path.push_back(root);
        
        if(!root->left && !root->right){
            int size = path.size();
            if(size>k){
                nodes.insert(path[size-k-1]);
            }
        }
        
        checkPath(root->left,path,k);
        checkPath(root->right,path,k);
        
        path.pop_back();
    }
};

// APPROACH:- 

// WHY I USED CEVTOR OF NODE* INSTED OF INT ???

// because there is aposibility that diff node have same value and as we will count unique nodes here so we must not get confuse the node is unique or not so to avoid the confusion i am creating it to store address of node
// for having unique nodes only i will use set here



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends