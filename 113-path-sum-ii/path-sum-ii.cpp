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

    void helperFun(TreeNode* root,int &targetSum,int & sum,vector<int>&path,vector<vector<int>>&ans){
     
       if(!root) return;

       sum+=root->val;
       path.push_back(root->val);

       if(!root->left && !root->right){
        if(sum==targetSum){
            ans.push_back(path);
        }
       }

       helperFun(root->left,targetSum,sum,path,ans);
       helperFun(root->right,targetSum,sum,path,ans);

       sum-=root->val;
       path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        helperFun(root,targetSum,sum,path,ans);
        return ans;
    }
};