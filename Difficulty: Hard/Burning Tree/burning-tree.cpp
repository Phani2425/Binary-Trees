//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
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
class Solution {
  public:
  

  
Node* findAddress(Node* root, int target) {
    if (!root) {
        return NULL;
    }
    if (root->data == target) {
        return root;
    }
    
    // Recursively search in the left subtree
    Node* leftResult = findAddress(root->left, target);
    if (leftResult) {
        return leftResult;
    }
    
    // If not found in the left subtree, search in the right subtree
    return findAddress(root->right, target);
}

  
  int findHeight(Node* tar){
      if(!tar){
          return 0;
      }
      
      return 1+max(findHeight(tar->left),findHeight(tar->right));
  }
  
  //function for step 2
    int minimumTime = INT_MIN;
    
  int findTime(Node* root, int target){
      
      if(!root){
          return 0;
      }
      if(root->data == target){//burning staqrts here
          return -1;
      }
      
      int left = findTime(root->left,target);
      int right = findTime(root->right,target);
      
      if(left<0){//burning is comimg form left
          minimumTime = max(minimumTime,abs(left)+right);
          return left-1;
      }
      else if(right<0){//burning is comimg form right
          minimumTime = max(minimumTime,abs(right)+left);
          return right-1;
      }
      else{//if both are positive means burn is not coming from anywhere
          return 1+max(left,right);
      }
  }
  
    int minTime(Node* root, int target) 
    {
        //step 1
        //find the time required to burn the descendent nodes of the target node
        //for that find the address of that node
        Node * tar = findAddress(root,target);
        
        //then find its height
        int h = findHeight(tar)-1;//substracting -1 as if  height of a node is 3 then for buring its decendents it eill take time of 2 as a single edge takes 1 sec for burning
        
        //step 2
        //finding the time required to burn the other nodes except the decendent ones
         findTime(root,target);
        
        //then among  these two the maximum time will be the answer
        
        return max(h,minimumTime);
        
    }
};

//APPROACH:- quetion has asked us to find out the minimumm time it will take to burn the whole tree if a node is set in fire
//mane basically the time required to burn the node which is present at maximum distance fromm the target node will be the minimum time required for burning the whole tree
//becayse the node at max distance from the target node will burn at last and untill then all other  nodes will be already burned
//so here our workk is to see that what which node is present at maximum distance that the target node and how many time it will take to get burned [that will be our answer]

//let call  the node at maximum distance :- maxnode
//now there are two possibility :- either the maxnode will be descendent of the target node[in case where target node is root node or some node of higher level]
//another possiblity is the maxnode is present outside the subtree made by the target node

//so we will explore both possiblity and finout what will be the time required to burn all its decendant and what will be the time required to burn all other nodes except its decendents

//ok for 1st one we can findout the time required to burn its decendent tree by just finding out the height of the target node
//for which we will first find the address of the target node
//then using recursion we will find the height of that target node

//for 2nd one what we will do:- here comes the tricky part:- for each node the time required to burn its all decendent nodes = its height + time required for the burn to reach near it
//so mu sabu node pakhaku jaiki pachari paribi ki tamaku tama sabu decendent jaleibaku total kete time lagiba???
//au mu gote global variable declare karithibi au sabu thara mu sei global variable au current node ra answer bhitaru maximum find kariki sei variable re store karibi
//because ultimately the maximum time taken by a node among all nodes in the whole tree will be the minimum time required to burn the while tree

//but ethi problme asiba ki burn ta gote side ru asuthiba au taku sabu node pakhaku asibaku bi time lagiba so gote nod epakhaku burn pahanchi baku kete time llagiba seta ame kemiti kahipariba untill burn reach there

//so ame kn kariba ki sabu node pakahku jiba using recurion and taku pachariba ki kn to left node side ru burn asuchi.... jadi asuchi then mate kaha mu jaliabku au kete time lagiba
//au jadi asuni then kaha mora height kete

//and to  differentiate betwwen height and burn time we will pass burn time as negative number




//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends