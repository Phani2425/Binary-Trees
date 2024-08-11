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

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.

//THE MAIN POINT TO KNOW IS ANYONE WHO KNOWS VARIOUS TREE TRAVERSAL WAYS CAN SOLVE MAJORITY OF BINARY TREE PROBLEMS 
//THE WAYS FOR TREE TRAVERSAL ARE 1. LEVEL ORDER TRVERSAL AND RECURSION
//1. IN LEVEL ORDER TRAVERSAL THE TREE IS TRAVERSED LEVEL BY LEVEL ALONG WITH ELEMENTS WILL ME INSERTE INTO THE  QUEUE ACCORDING TOTHEIR RESPECTIVE LEVEEL
//MEANS ELEMENTS AT LEVEL ONE WILL BE INSERTED FIRST THEN LEVEL 2 THEN IT GOES ON.... AND ELEMENTS PRESENT IN THE QUEUE TOO PROCESSED LEVEL BY LEVEL

// 2. IN RECUSION METHOD WE HAVE FLEXIBILITY TO TRRAVERSE THE TREE WE CAN TRAVERSE IT AS INORDER,PREORDER,POSTORDER ETC

//HERE TOO I WILL SOLVE THIS BY USING BOTH WAYS

//METHOD :- 1 {LEVEL ORDER TRAVERSAL}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   queue<Node *> q;
   q.push(root);
   
   while(!q.empty()){
       int currSize = q.size();
       ans.push_back(q.front()->data);
       
       while(currSize--){
           Node * currNode = q.front();
            q.pop();
           if(currNode->left){
               q.push(currNode->left);
           }
           if(currNode->right){
               q.push(currNode->right);
           }
       }
   }
   
   return ans;
}


//method -2 (recursive mthod) [inteerviewere might ask me to solvve this without using queue]

void helperFunction(Node * root, vector<int> & ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    helperFunction(root->left,ans,level+1);
    helperFunction(root->right,ans,level+1);
}

vector<int> leftView(Node *root)
{
  vector<int> ans;
  helperFunction(root,ans,0);
  
  return ans;
}

//in this method the logic is i will traverse the tree using recyrsion but alsoi will keep look on which level on i am 
//mane mu basicaly jetebele got specific level ku first time pain jibi setebele mu sei node ra data ku ans re store karidebi 
//mu ethire unordered map use kariparibi jouthire mu level ku key nebi au sei level ra leftmost data ku value rakhibi
//and each time i will go to a new node i will check that in the map do i have any element against the current level i am \//if yes then i will not store as i have already visited that level
//but if no the i will store the data of that node against current level as it's key

//ANOTHER WAY
//here i will not use map i will use simokle logic to solve the question 
// where also i have to remember the level no i am currently in but to check if i have already visited this level or not i will use the size of the ans vector
//mane ans vector re mu every level ra left most element entry karibi.... so jadi mu ebe 2nd level ku assili then mu check karibi mo ans vector ra size kete
//jadi size 2 thiba (LEFT MOST DATA OF 0TH AND 1ST LEVEL) then mu 2nd level ku first ttime pain asichi so i will push the data au jadi size 2 ru adhika thiba then mu laready 3rd level ra left most element push karisarichi au ebe mu 3rd level ku again visit karuchi
//BASICALLY THE SIZE OF ANS VECTOR = NO OF LEVELS FOR WHICH  I HAVE ALREADY PUSHED THE LEFT MOST ELEMENT IN ANS
