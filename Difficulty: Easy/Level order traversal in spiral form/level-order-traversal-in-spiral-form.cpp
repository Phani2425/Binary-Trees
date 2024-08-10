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

vector<int> findSpiral(Node *root);

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
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    ans.push_back(root->data);
    deque<Node *>dq;
    int countNode = 0;
    if(root->left){
        ans.push_back(root->left->data);
        dq.push_front(root->left);
        countNode++;
    }
    if(root->right){
        ans.push_back(root->right->data);
        dq.push_front(root->right);
        countNode++;
    }
    
    int dir = 1;//dir value is 1 when we go fron odd level to even and 0 whenn we go to even level to odd
    
    int i = 1,count = 0;
    while(i <= countNode){
        if(dir == 0){
            Node * currNode = dq.back();
            if(currNode->left){
                ans.push_back(currNode->left->data);
                dq.push_front(currNode->left);
                count++;
            }
            if(currNode->right){
                ans.push_back(currNode->right->data);
                dq.push_front(currNode->right);
                count++;
            }
            dq.pop_back();
            if(i == countNode){
                countNode += count;
                count = 0;
                dir = !dir;
            }
        }
        else if(dir == 1){
            Node * currNode = dq.front();
            if(currNode->right){
                ans.push_back(currNode->right->data);
                dq.push_back(currNode->right);
                count++;
            }
            if(currNode->left){
                ans.push_back(currNode->left->data);
                dq.push_back(currNode->left);
                count++;
            }
            dq.pop_front();
            if(i == countNode){
                countNode += count;
                count = 0;
                dir = !dir;
            }
            
        }
        
        i++;
    }
    
    return ans;
    
}
