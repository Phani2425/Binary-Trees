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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }

        int repeat = depth-2;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && repeat--){
           int size = q.size();
           while(size--){
            TreeNode* temp = q.front();
           q.pop();
           if(temp->left){
            q.push(temp->left);
           }
           if(temp->right){
            q.push(temp->right);
           }
           }
        }

        while(!q.empty()){
           TreeNode* temp = q.front();
           q.pop();
           TreeNode* leftchild = new TreeNode(val);
           leftchild->left = temp->left;
           temp->left = leftchild;
           TreeNode* rightchild = new TreeNode(val);
           rightchild->right = temp->right;
           temp->right = rightchild;
        }

        return root;
    }
};