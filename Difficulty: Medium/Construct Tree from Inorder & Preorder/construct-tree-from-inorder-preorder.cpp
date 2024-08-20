//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    //function for finding the position of the first element of the preorder array  in inorder array
    int findPosition(int in[], int inStart,int inEnd, int element){
        for(int i = inStart;i<=inEnd;i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;//not mandatory just for safety purpose as every elemnt in the pre array will present in the in array for sure
    }
    
    Node * buildTreeWithRecursion(int in[], int pre[], int inStart, int inEnd, int index){
        //base case
        if(inStart > inEnd){
            return NULL;
        }
        
        //recursive case
        //build the current node first
        Node * root = new Node(pre[index]);
        //find the position of the element in inorder which is present in "index" of preorder
        int position = findPosition(in,inStart,inEnd,pre[index]);
        
        //then devide the inorder array and go to left subtree to build that
        root->left = buildTreeWithRecursion(in,pre,inStart,position-1,index+1);
        
        //then go to right subtree to build that
        root->right = buildTreeWithRecursion(in,pre,position+1,inEnd,index+(position-inStart)+1);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return buildTreeWithRecursion(in,pre,0,n-1,0);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends