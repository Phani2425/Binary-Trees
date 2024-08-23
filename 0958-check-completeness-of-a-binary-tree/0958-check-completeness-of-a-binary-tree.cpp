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