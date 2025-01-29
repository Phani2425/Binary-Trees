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
    bool isEvenOddTree(TreeNode* root) {

        bool isEven = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
                int prev = isEven ? 0 : INT_MAX;
                while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(isEven){
                    if(temp->val%2 == 0 || temp->val<=prev){
                        return false;
                    }

                }else{
                    if(temp->val %2 != 0 || temp->val >= prev){
                        return false;
                    }
                }
                prev = temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

            }
                isEven = !isEven; 
        }

       return true;
        
    }
};