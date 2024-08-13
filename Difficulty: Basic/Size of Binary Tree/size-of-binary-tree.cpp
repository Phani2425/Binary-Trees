//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* inputTree(){
    string treeString;
    getline(cin,treeString);
    Node* root = buildTree(treeString);
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// } Driver Code Ends
/*

Definition for Binary Tree Node
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
  
  //METHOD - 1
  
//   //global variable which will be same for every recursive call and hence will be passed as reference
//   int count = 0;
//   //function for counting the no of nodes using recursion
//   void TotalNodes(Node * root, int & count){
//       //base case
//       if(root == NULL){
//           return;
//       }
      
//       //recursive case
//       //current node ko count karlo
//       count++;
//       //left me jao
//       TotalNodes(root->left, count);
//       //right me jso
//       TotalNodes(root->right, count);
//   }
  
//     int getSize(Node* node) {
//         // code here
//         TotalNodes(node, count);
        
//         return count;
        
//     }

  //METHOOD - 2
  
  int getSize(Node* node){
      //base case
      if(root == NULL){
          return 0;
      }
      
      //recursive case
      return (1 + TotalNodesMethod2(root->left) + TotalNodesMethod2(root->right));
  }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        Node* node = inputTree();
        
        Solution obj;
        int res = obj.getSize(node);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
