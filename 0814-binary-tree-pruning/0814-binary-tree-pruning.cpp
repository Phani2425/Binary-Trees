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
class Solution {
public:

//SOLVED USING DFS AND BOTTOM UP APPROACH...THINK WHY BUTTOM UP APPROACH???? TAKE HELP OF CHAT GPT
    TreeNode* pruneTree(TreeNode* root) {
       if(!root){
        return NULL;
       } 

       root->left = pruneTree(root->left);
       root->right = pruneTree(root->right);

       if(root->left || root->right || root->val == 1){
        return root;
       }
       else{
        return NULL;
       }
    }
};