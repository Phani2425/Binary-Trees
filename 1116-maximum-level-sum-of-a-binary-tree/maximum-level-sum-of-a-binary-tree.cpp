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

    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int minLvl = INT_MAX;
        int currLvl = 1;
        
        while(!q.empty()){
            int size = q.size();
            int sum = 0;  

            while(size--){

                TreeNode* temp = q.front();
                sum += temp->val;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

            }

             if(sum > maxSum){
               maxSum = sum;
               minLvl = currLvl;
            }
            currLvl++;
        }

        return minLvl;
    }
};