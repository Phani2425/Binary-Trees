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
    if (node == NULL)
        return;

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

class Solution {
  public:
  
  //function for finding position inn the inorder array
  int findPositionInInorder(int in[],int inStart,int inEnd, int element){
      for(int i=inStart;i<=inEnd;i++){
          if(in[i] == element){
              return i;
          }
      }
      return -1;
  }
  
  Node* buildTreeWithRecursion(int in[],int post[],int inStart,int inEnd, int index){
      //base case
      if(inStart > inEnd){
          return NULL;
      }
      
      //recursive case
      
      Node* root = new Node(post[index]);
      
      int position = findPositionInInorder(in,inStart,inEnd,post[index]);
      
      //left subtree
      root->left = buildTreeWithRecursion(in,post,inStart,position-1,index-(inEnd-position)-1);
      //right subtree
      root->right = buildTreeWithRecursion(in,post,position+1,inEnd,index-1);
      
      return root;
  }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        //we know from some previous questions like: - "iterative postorder traversal" that postorder or [LRN] traversal of a tree is 
        // equal to the reverse of [NRL] traversal of that same tree} means if postorder is given and we reverse that we will get the [NRL] traversdal of that tree
        
        //so we can solve this question by reversing the given postorder traversal and then traversing it from left to right otherwise
        //we can solve this by travesing the given postorder in right to left direction
        
        //we will solve this without reversing it
        
        return buildTreeWithRecursion(in,post,0,n-1,n-1);
    }
        
        
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends