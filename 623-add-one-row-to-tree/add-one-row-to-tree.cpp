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

//  SOLVING IT IN BFS

// class Solution {
// public:
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth == 1){
//             TreeNode * temp = new TreeNode(val);
//             temp->left = root;
//             return temp;
//         }

//         int repeat = depth-2;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty() && repeat--){
//            int size = q.size();
//            while(size--){
//             TreeNode* temp = q.front();
//            q.pop();
//            if(temp->left){
//             q.push(temp->left);
//            }
//            if(temp->right){
//             q.push(temp->right);
//            }
//            }
//         }

//         while(!q.empty()){
//            TreeNode* temp = q.front();
//            q.pop();
//            TreeNode* leftchild = new TreeNode(val);
//            leftchild->left = temp->left;
//            temp->left = leftchild;
//            TreeNode* rightchild = new TreeNode(val);
//            rightchild->right = temp->right;
//            temp->right = rightchild;
//         }

//         return root;
//     }
// };


// way-2
//  SOLVING IT IN DFS

class Solution {
public:

    void helperFun(TreeNode* root, int& val, int& depth,int currDepth){
        if(!root)return;

        if(currDepth == depth-1){
           TreeNode* leftchild = new TreeNode(val);
           leftchild->left = root->left;
           root->left = leftchild;
           TreeNode* rightchild = new TreeNode(val);
           rightchild->right = root->right;
           root->right = rightchild;
        }

        helperFun(root->left,val,depth,currDepth+1);
        helperFun(root->right,val,depth,currDepth+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }

        helperFun(root,val,depth,1);

        return root;
    }
};