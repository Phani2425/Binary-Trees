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

    bool helperFun(TreeNode* root,int targetSum,int &sum){

        if(!root) return false;

       sum+=root->val;
       if(!root->left&&!root->right){
        bool res =  sum==targetSum;
        sum-=root->val;
         return res;
       }


        bool left = helperFun(root->left,targetSum,sum);
        bool right = helperFun(root->right,targetSum,sum);

        sum-=root->val;

        return (left||right);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
       return helperFun(root,targetSum,sum);
    }
};