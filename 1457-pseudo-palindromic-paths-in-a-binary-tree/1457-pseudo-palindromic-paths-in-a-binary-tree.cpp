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
int count = 0;


    void helperFunction(TreeNode* root, int value){
        if(!root){
            return;
        }

        value = value ^ (1<<root->val);

        if(root->left == NULL && root->right == NULL){
           if((value & (value-1)) == 0){
            count++;
           }
        }

        helperFunction(root->left,value);
        helperFunction(root->right,value);


    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;

        helperFunction(root,0);

        return count;
    }
};