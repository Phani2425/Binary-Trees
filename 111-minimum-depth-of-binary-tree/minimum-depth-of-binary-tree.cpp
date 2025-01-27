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

//  SOLUTION USING BFS (MORE INTUTIVE)
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(!root){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int currLvl = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                // jaha pe bhi first leaf mila bas level return kardo
                if(temp->left==NULL && temp->right==NULL){
                    return currLvl;
                }

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
            currLvl++;
        }
        return 0;
    }
};

// SOLUTION USING DFS

// simillar to finding height of tree