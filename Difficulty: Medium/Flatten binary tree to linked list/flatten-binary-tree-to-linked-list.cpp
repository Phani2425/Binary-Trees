//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

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
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void flatten(Node *root)
    {
       while(root){
           if(!root->left) root = root->right;
           else{
               Node * temp = root->left;
               while(temp->right){
                   temp = temp->right;
               }
               temp->right = root->right;
               root->right = root->left;
               root->left = NULL;
               root=root->right;
           }
       }
    }
};


// SOLUTION APPROACH:-

// okk so it was a quite intutive solution a swe just need to find the pattern in whichh the linkedlist will be created .
// imagine if sommeone asked us to estabilish new connection ,remove connection or do whatever you wanty to do but creatte a linkedlist outof a tree in place where the right pointer of a node
// will point ti the next node in LL and the left pointer will point to NULL

// so while doing this thing we will notice two things :- 
    
//     1. if a node do not have any left subtree then we do not have to change anyhting in it because it has NULL in its left and it is pointing to the right chiild from begining which we want in a LL
//     2. if a node {let N} have any left child then:- 
//       2.1. first of all the the node N should point towards left subtree by its right pointer but if we do this first then we will loose coonection between node N and its right subtree if there is any
//       2.2. 2nd is always if there is left subtree of Node N the the right most child of that left subtreee will point to the right child of Node N
       
//       ok so i got an idea if i perform the 2nd point first and then the 1st point then my link will be estabilished and aslo i wont loose coonection with right one
//       and as we have to put the left pointer of nodes as NUll and estabilish only right  pointer connection then for sure we will reach to the end of nodes so we will use this logic 
//       to check wheather a node have lleft child or not and apply the above pattern we have seen in it
       
//     ->Basically we will do what:-  if a node dont have left then direct move to right 
//                                     else cerate  temp pointer to go to the right most child of the left subtree and establish connnection to the right node of actual node where we are now
//                                     then break the link between actual node and its right and connect the node to the left subtree root 
//                                     and move right [as we attached tthe left subtree to right so we are just going to the leeft subtree]



//{ Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	
cout << "~" << "\n";
}

	return 0;
}

// } Driver Code Ends