//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isCousins(Node* root, int x, int y);

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        if (x == y) {
            cout << "0\n";
            continue;
        }
        cout << isCousins(root, x, y) << endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//checks if a and b have same parent if yes returns true else false
bool isSameParent(Node*root, int a,int b){
    if(!root){
        return false;
    }
    if(root->left && root->right){
        if(root->left->data == a && root->right->data == b){
            return true;
        }
        if(root->right->data == a && root->left->data == b){
            return true;
        }
    }
    
    return (isSameParent(root->left,a,b) || isSameParent(root->right,a,b));
}

// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b) {
    //1.find the levels of both numbers:- if same then go to condition 2 else return false
    int levelOfa = -1,levelOfb = -1;
    queue<Node*>q;
    q.push(root);
    int currLevel = 0;
    
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data==a){
                levelOfa = currLevel;
            }
            if(temp->data==b){
                levelOfb = currLevel;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        currLevel++;

        //edge case:- agar sare level dhundne ke baad bhi a aur b ka level nehi mila then iska matlab ye hai ki wo tree me hai hi nehi
    //so return false
        if(levelOfa != levelOfb ){
                return false;
        }
        
        if(levelOfa != -1){

            break;
        }
        
        
    }
    
    if(levelOfa==-1 && levelOfb==-1){
        return false;
    }
    
    return !isSameParent(root,a,b);
}
