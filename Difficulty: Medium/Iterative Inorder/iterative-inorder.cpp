//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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


// } Driver Code Ends
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/

//here basically it is asking us to print the node when i will pass that node for second time(try it making a tree and traversing it)
//to ame kn kariba na:- ame first root node ku stack re pureidaba for starting the loop
//tapare jejae stack khali naheichi sete jae top re thiba address ku bahara kariba au taku pop karidaba stack ru
//then check kariba je kn ie address map re present achi???jadi nahi tahele taku map re add kkaridaba as key and 1 as its value
//but ebe ame aku print kariparibani as it is our first visit so ame ara right node then ei node itself and then left node ku stack re push karidaba
//because ethi amaku L->N->R order re traverse karibara achi au sethipain ame right node ku sabuthu tale au left node ku sabuthu upare rakhiba au node ku majhire push kariba due to their proiprity
// jadi map re ei address achi ta mane ame etaku agaru thare visit karithile sethipain eta map re achi au ame ebe taku second time pain visit karuche so tara data ku push karidaba ans bhitaraku
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        stack<Node*>st;
        vector<int> ans;
        unordered_map<Node*,int>map;//onordered map which will store the no of times i visited a address
        
        st.push(root);
        
        while(!st.empty()){
            Node *temp = st.top();
            st.pop();
            if(map[temp]){
                ans.push_back(temp->data);
            }else{
                map[temp]=1;
                if(temp->right){
                    st.push(temp->right);//push right
                }
                st.push(temp);//push that node itself
                if(temp->left){
                    st.push(temp->left);//push left
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.inOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends