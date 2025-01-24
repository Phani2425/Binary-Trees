//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //function to findout the extremes of   the tree
    void findExtremes(Node * root, int& l, int& r, int verticalLevel){
        if(!root){
            return;
        }
        
        l = min(l,verticalLevel);
        r = max(r,verticalLevel);
        
        findExtremes(root->left,l ,r, verticalLevel-1);
        findExtremes(root->right,l ,r, verticalLevel+1);
    }
    
    
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        int leftExtreme = 0, rightExtreme = 0; //assuming the tree have only one node and so both left and right extremes lies at level 0
        //in this  way we can also handle the edge case where the no of nodes  is 1
        
        //calling a function which will give us the left and right extreme value
        findExtremes(root,leftExtreme,rightExtreme,0 );
        
        vector<vector<int>> negative(abs(leftExtreme)+1);
        vector<vector<int>>positive(rightExtreme+1);
        
        queue<Node*>q;
        queue<int>index;
        
        q.push(root);
        index.push(0);
        
        while(!q.empty()){
            Node * temp = q.front();
            q.pop();
            int ind = index.front();
            index.pop();
            
            if(ind>=0){
                positive[ind].push_back(temp->data);
            }
            else{
                negative[abs(ind)].push_back(temp->data);
            }
            
            if(temp->left){
                q.push(temp->left);
                index.push(ind-1);
            }
            if(temp->right){
                q.push(temp->right);
                index.push(ind+1);
            }
        }
        
      vector<int> ans;
      
      //traversing the negative vector in reverse order upto its index 1
      for(int i=negative.size()-1;i>0;i--){
          for(int j : negative[i]){
              ans.push_back(j);
          }
      }
      
      //traversing the positive vector in normal order
      for(int i=0;i<positive.size();i++){
          for(int j :positive[i]){
              ans.push_back(j);
          }
      }
      
      return ans;
        
    }   
       
};

//THEN I SOLVED IT IN A SINGLE ARRAY

 // vector<int> verticalOrder(Node *root)
 //    {
 //        int extremeLeft=0,extremeRight=0;
 //        helperFun(extremeLeft,extremeRight,root,0);
        
 //        int size = extremeRight-extremeLeft+1;
        
 //        vector<vector<int>>ans(size);
 //        queue<Node*>q;
 //        queue<int>level;
 //        q.push(root);
 //        level.push(0);
        
 //        while(!q.empty()){
 //            Node* temp = q.front();
 //            q.pop();
 //            int currLvl = level.front();
 //            level.pop();
 //            ans[abs(extremeLeft)+currLvl].push_back(temp->data);
 //            if(temp->left){
 //                q.push(temp->left);
 //                level.push(currLvl-1);
 //            }
 //            if(temp->right){
 //                q.push(temp->right);
 //                level.push(currLvl+1);
 //            }
 //        }
        
 //        vector<int>Finalans;
 //        for(auto v:ans){
 //            for(int node:v){
 //                Finalans.push_back(node);
 //            }
 //        }
        
 //        return Finalans;
        
 //    }



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends
