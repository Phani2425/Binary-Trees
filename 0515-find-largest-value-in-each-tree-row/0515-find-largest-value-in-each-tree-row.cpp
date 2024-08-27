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
//this can easily solevd using bfs tarversal so lets try it using dfs tarversal

    vector<int> ans;
    int maxHeight=0;
   

    void findHeight(TreeNode* root, int currLevel ){
        if(!root){
            return;
        }
        maxHeight = max(maxHeight,currLevel);

        findHeight(root->left,currLevel+1);
        findHeight(root->right,currLevel+1);
        
    }

    void helperFunction(TreeNode* root, vector<int>& ans, int currLevel){
        if(!root){
            return;
        }

        ans[currLevel] = max(ans[currLevel],root->val);

        helperFunction(root->left,ans,currLevel+1);
        helperFunction(root->right,ans,currLevel+1);
    }

    vector<int> largestValues(TreeNode* root) {

        findHeight(root,1);
        vector<int> ans(maxHeight, INT_MIN);
        helperFunction(root,ans,0);

        return ans;
        
    }
};