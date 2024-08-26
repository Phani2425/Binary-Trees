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
    int maxPath = 0;

    void solve(TreeNode* root,int right,int left){
        if(!root){
            return;
        }

        maxPath = max(maxPath,max(left,right));

        solve(root->left,0,right+1);
        solve(root->right,left+1,0);
    }

    int longestZigZag(TreeNode* root) {
        solve(root,0,0);

        return maxPath;
    }
};