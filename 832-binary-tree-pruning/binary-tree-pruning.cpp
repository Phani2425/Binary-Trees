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
int helperFun(TreeNode * root) {
 if(!root)return 0;

 int left = helperFun(root->left);
 int right = helperFun(root->right);

 if(left == 0){
    root->left = NULL;
 }
 if(right == 0){
    root->right = NULL;
 }

 return root->val+left+right;
}
    TreeNode* pruneTree(TreeNode* root) {
       int whole = helperFun(root);
    //    there is a chance that the subtree attached with root after all deletion have all zero's in that case we need to return NULL as there is no root
    if(whole==0){
        return NULL;
    }

        return root;
    }
};