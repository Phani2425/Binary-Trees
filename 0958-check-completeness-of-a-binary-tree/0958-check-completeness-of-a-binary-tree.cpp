/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//SOLUTION USING BFS (BASICALLY USING QUEUE)

//SABU NODE PAKHAK JAIKI MUNPACHARIBI KI BHAI GARU KN KICHI NULL NODE DEKHICHA KI JADI HMM THEN TAME COMPLETE BINARY TREE NUHA
//BECAUSE COMP BINARY TREE RE WHEN WE APPLY BFS AND ENTETR ALL NODES INTO QUEUE SETEBELE KEBEBI GOTE NODE PURBARU NULL NODE ASIBA HI NAHI
//BECAUSE IN COMP B.T ALL LEVELS ARE COMPLETELY FILLED AND NODES AT LAST LEVEL ARE AS LEFT AS POSSIBLE
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        //edge case
        if(!root->left && !root->right){//single node condition
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool haveYouSawNull = false;

        while(!q.empty()){
           TreeNode * temp = q.front();
           q.pop();
           if(!temp){
            haveYouSawNull = true;
           }
           else{
            if(haveYouSawNull){
                return false;
            }
            q.push(temp->left);
            q.push(temp->right);
           }
        }

        return true;
    }
};


//METHOD - 2 [USING DFS]
//i learnt here taht a binary tree can also be represente ad an array means the nodes of a binary tree can be representewd as the elements of array
//where each node will have a specific index value
//lets understand how it acts:- 
//Always the root node is considered to have a index of 1
// if a parent node have an index of "i" then its left child will have an index of "2*i" and its right child will have an index of "2*i+1" 
//so in complete binary trees the no of nodes should be equal to the last index as indexing starts form 1 and in completebinary tree the nodes are present as left as possible

//but due to rapid growth of index value in very deep tree or one sided tree it might give integer overflow error
class Solution {
public:

    void checkCompleteness(TreeNode* root, long long int index, bool& flag,int noOfNode){
        if(!root){
            return;
        }
        if(index > noOfNode){
            flag = false;
        }
        checkCompleteness(root->left,index*2,flag,noOfNode);
        checkCompleteness(root->right,index*2+1,flag,noOfNode);

    }

    //function for counting node
    int countNode(TreeNode* node){
        if(!node){
            return 0;
        }
        return 1+countNode(node->left)+countNode(node->right);
    }

    bool isCompleteTree(TreeNode* root) {
        bool flag = true;
      //calculate the no of nodes
      int noOfNode = countNode(root);
      //call the recursive function
      checkCompleteness(root,1,flag,noOfNode);
      //check if it is complete tree or not by flag
      if(flag){
        return true;
      }
      return false;
       
    }
};
