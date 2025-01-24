//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node(val);
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Function to print nodes in a given doubly linked list */
void printList(Node* node) {
    Node* prev = NULL;
    while (node != NULL) {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL) {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}


// } Driver Code Ends
/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution {
  public:
  
  void helperFun(Node* root, Node* & head, Node*& prev){
      
      if(!root) return;
      
      helperFun(root->left,head,prev);
      
      if( head == NULL){
          head = root;
          root->left=NULL;
          prev = root;
      }
      else{
          prev->right = root;
      root->left = prev;
      prev=root;
      }
      
      helperFun(root->right,head,prev);
      
  }
  
    Node* bToDLL(Node* root) {
        Node * head = NULL;
        Node* prev =NULL;
        helperFun(root,head,prev);
        return head;
    }
};

 
//  SOLUTION APPROACH

// HERE IT HAS ASKED ME TO USE O(h) fro sloving this which is basically thee recursive stack space

// i tried to finout any  paattern to solve this without recursion as we solevd the problrem of flttening thhe b.t into linkedlist {preorder} but got stuck as here 
// the traversal technique told is inorder in whichh finding pattern is quite deififcult and i found one pattern but to write that and executre that in code is quite hard

// so we will use recursion to solve this :- 

// The idea behind solving this was quite easy and intuitive , just think how normally you used to print the inorder traversal of atree :- you call to left subtree -> print node -> call to right subtree

// so just think a small b.t with three nodes and two levels so after calling to left subtree when you reach to annode to explore or print that at that point if you had the prev node explored or printed then you can just 
// connect them with eeach other and update the current node as the prevNode for its attachment with next node to be explored

// how easy this was right???

// there will be some small edge cases such that the first node in inorder wonthave any prev node and also there wont be any head node so to tackle that just put a condition that if heead node is null or the prev node is null then 
// just create a node and assign that as head node and also update that as prev node .


 
 


//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        Node* head = ob.bToDLL(root);
        printList(head);

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends