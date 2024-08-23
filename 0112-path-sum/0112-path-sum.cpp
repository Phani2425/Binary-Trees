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
    bool flag = false;
    void hasPathSumHelper(TreeNode* node,int targetSum,int currentSum){
       if(!node){
        return;
       }
       currentSum += node->val;
       if(currentSum == targetSum && (node->left == NULL && node->right == NULL)){
        flag = true;
        return;
       }

       hasPathSumHelper(node->left,targetSum,currentSum);
       hasPathSumHelper(node->right,targetSum,currentSum);       
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        hasPathSumHelper(root,targetSum,0);
        return flag;
    }
};