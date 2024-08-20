//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//Back-end complete function Template for C++

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int value){
        this->data = value;
        this->left = this->right = NULL;
    }
};

class Solution{
    public:
    
    int valid = 1;
    
    bool match(Node * root1,Node * root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 && root2 || !root2 && root1){
            return false;
        }
        if(root1->data != root2->data){
            return false;
        }
        
        return match(root1->left, root2->left) && match(root1->right ,root2->right);
    }
    
    //function for finding out the position of the element {first element of the current inorder array}
    int findPosition (int inorder[],int inStart,int inEnd,int element){
        for(int i = inStart;i<=inEnd;i++){
            if(inorder[i] == element){
                return i;
            }
        }
        
        return -1;
    }
    
    //function for building tree from inorder and preorder traversal
    Node * InorderAndPreorder(int inorder[],int preorder[],int inStart,int inEnd,int index){
        //base case
        if(inStart > inEnd){
           
            return NULL;
        }
        
        // recursive case
        Node * root = new Node(preorder[index]);
        int position = findPosition(inorder,inStart,inEnd,preorder[index]);
        
        //edge case as there is posibility that some element might be presesnt in a array and not in another among preorder,postorder and inorder
        if(position == -1){
            valid = 0;
            return NULL;
        }
        
        root->left = InorderAndPreorder(inorder,preorder,inStart,position-1,index+1);
        root->right = InorderAndPreorder(inorder,preorder,position+1,inEnd,index+(position-inStart)+1);
        
        return root;
    }
    
    //function for building tree from inorder and postorder traversal
    Node * InorderAndPostorder(int inorder[],int postorder[],int inStart,int inEnd,int index){
        //base case
        if(inStart > inEnd){
            return NULL;
        }
        
        //recursive case
        Node * root = new  Node(postorder[index]);
        int position = findPosition(inorder,inStart,inEnd,postorder[index]);
        
        //edge case as there is posibility that some element might be presesnt in a array and not in another among preorder,postorder and inorder
        if(position == -1){
            valid = 0;
            return NULL;
        }
        
        root->left = InorderAndPostorder(inorder,postorder,inStart,position-1,index-(inEnd-position)-1);
        root->right = InorderAndPostorder(inorder,postorder,position+1,inEnd,index-1);
        
        return root;
    }
    
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
    	
    	//building tree from inorder and preorder
    	Node * root1 = InorderAndPreorder(inorder,preorder,0,N-1,0);
    	
    	//building tree form inorder and postorder
    	Node * root2  = InorderAndPostorder(inorder,postorder,0,N-1,N-1);
    	
    	if(valid == 0){
    	    return false;
    	}
    	
    	//matching both
    	 return match(root1 ,root2);
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
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 


// } Driver Code Ends