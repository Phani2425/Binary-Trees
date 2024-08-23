//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    //gloabal varibale for maximum pathsum which will be used to compare the pathsum of path passing thorogh each node
    //upon comparing we will get the maximum possible value of pathsum from all posiible path sums
    int maximumPathSum = INT_MIN;

    int maxPathSumHelper(Node* root)
    {
        //base case
        if(!root){
            return 0;
        }
        // If the node is a leaf node, return its value
        if (!root->left && !root->right) {
            return root->data;
        }
        
        //recursive case
        int leftSubtreePathSum = maxPathSumHelper(root->left);
        int rightSubtreePathSum = maxPathSumHelper(root->right);
        
        
        if(!root->right){
            return root->data+leftSubtreePathSum;
        }
        if(!root->left){
            return root->data+rightSubtreePathSum; 
        }
        if(root->left && root->right){//matlab dono side trees hai
            maximumPathSum = max(maximumPathSum, (root->data + leftSubtreePathSum + rightSubtreePathSum));
            return (root->data + max(leftSubtreePathSum, rightSubtreePathSum));
        }

    }
    
    int maxPathSum(Node * root){
        
        int ansWhenRootIsLeaf = maxPathSumHelper(root);
        
        //root node itself can be a leaf node if it do not have left or right node
        //so of root node have both then we will directly return the maximumPathSum
        //else we will add the value of root node with it and then return...why???? because in recursive function we have  
        //defined a rule that only if a node have both left and right subtree then only maximumPathSum will get updated as
        //in that case only it becomes a valid path between two special nodes
        //and if a node is lacking either of two nodes then there is absence of one special node because except root node all other node if contains only one subtree
        //then that node must be connected to two nodes so it can't be a special node
        //this is why we will just return its data+the value of existing subtree without trying to update "maximumPathSum" as "maximumPathSum" is only tried to update when path is valid or between two special node
        
        //so now we wil write two conditions
        
        //if root node have both left and right subtree [then it can't be a leaf node] so we will directly return "maximumPathSum"
        if(root->left && root->right){
            return maximumPathSum;
        }
        //else root can be also a leaf node .as we are ignoring updation of "maximumPathSum" in single side subtree case hence in this case too it is not updated 
        //but it should get updated as root with single side subtree is also a leaf ... so it is an exception.....
        else{
           return max(maximumPathSum ,ansWhenRootIsLeaf); 
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends