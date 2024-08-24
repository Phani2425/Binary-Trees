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

//BFS SOLUTION WITHOUT CALCULATING THE HEIGHT

// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//        int ans;
//        queue<TreeNode*> q;
//        q.push(root);
//        while(!q.empty()){
//         ans = q.front()->val;
//         int size = q.size();
//         while(size--){
//           TreeNode* temp = q.front();
//           q.pop();
//           if(temp->left){
//             q.push(temp->left);
//           }
//           if(temp->right){
//             q.push(temp->right);
//           }
//         }
//        }

//        return ans; 
//     }
// };

//DFS SOLUTION

class Solution {
public:
    int ans;
    void helperFunc(TreeNode* root, int currLevel,int& maxlevel){
        if(!root){
            return;
        }
        if(currLevel >= maxlevel){
          maxlevel = currLevel;
          ans = root->val;
        }
        helperFunc(root->right,currLevel+1,maxlevel);
        helperFunc(root->left,currLevel+1,maxlevel);
        
    }

    int findBottomLeftValue(TreeNode* root) {
        int maxlevel = 0;
       helperFunc(root,0,maxlevel);

       return ans;
    }
};
