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

    long ans = 0;

    int helperFunction(TreeNode* root, long & totalSum){
      if(!root){
        return 0;
      }
      int leftSum = helperFunction(root->left,totalSum);
      int rightSum = helperFunction(root->right,totalSum);

      long currSubtreeSum = root->val+leftSum+rightSum;

      ans = max(ans,(currSubtreeSum * (totalSum-currSubtreeSum)));

      return currSubtreeSum;
    }

    long calTotalSum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val+calTotalSum(root->left)+calTotalSum(root->right);
    }

    int maxProduct(TreeNode* root) {
        long totalSum = calTotalSum(root);
        helperFunction(root,totalSum);
        return ans%1000000007;  
    }
};