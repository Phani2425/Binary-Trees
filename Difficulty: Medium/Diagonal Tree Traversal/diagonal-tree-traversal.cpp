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


vector<int> diagonal(Node *root);

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



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

//function to findout the left extreme
void findleftExtreme(Node* root,int &leftExtreme,int pos){
    if(!root){
        return;
    }
    leftExtreme=max(leftExtreme,pos);
    findleftExtreme(root->left,leftExtreme,pos+1);
    findleftExtreme(root->right,leftExtreme,pos);
}

//recursive function
void traverseDiagonal(Node *root,vector<vector<int>>&ans,int pos){
    if(!root){
        return;
    }
    
    ans[pos].push_back(root->data);
    traverseDiagonal(root->left,ans,pos+1);
    traverseDiagonal(root->right,ans,pos);
}

vector<int> diagonal(Node *root)
{
  int leftExtreme = 0;
  findleftExtreme(root,leftExtreme,0);
  
  vector<vector<int>> ans(leftExtreme+1);
  
  traverseDiagonal(root,ans,0);
  
  vector<int> finalAns;
  
  for(int i=0;i<ans.size();i++){
      for(int j:ans[i]){
          finalAns.push_back(j);
      }
  }
  
  return finalAns;
}


// step: 1:- find out the left extreme vertical level of the  tree
// steep:2:- create an 2d vector of size = leftExtreme+1
// step:3:- as this problem can not be solved using level order traversal hence we will recursion 
// and push the respective element into their respective place

// look in the first example the no-8 is at l-0,r-0 
// then 10 is at l-0,r-1 
// 14:-l-o,r-2
// as all of the are in l-0 so they will come in the ans vector first if we are traversing the tree in left to right diagonal order

// then:- 3:-l-1,r-0
// 6:-l-1,r-1
// 7:-l-1,r-2
// 13:-l-1,r-2
// so these will come together

// then:-
// 1:-l-2,r-0
// 4:-l-2,r-1
// so these two will come together

// so the ans will be:- 8 10 14 3 6 7 13 1 4

