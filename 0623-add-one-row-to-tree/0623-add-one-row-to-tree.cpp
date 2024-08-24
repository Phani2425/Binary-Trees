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
        //edge case where depth is 1
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 1;
        while(!q.empty()){
            int size = q.size();
            if(currDepth == depth-1){
              while(size--){
                TreeNode* temp = q.front();
                q.pop();
                //for creating left subtree root
                TreeNode* tempLeft = new TreeNode(val);
                if(temp->left){
                    tempLeft->left = temp->left;
                }
                //left ho na ho ye new node temp ke left me add hoga
                temp->left = tempLeft;
                //for creating right subtree root
                TreeNode* tempRight = new TreeNode(val);
                if(temp->right){
                    tempRight->right = temp->right;
                }
                ///similar for right
                temp->right = tempRight;
              }
              //now we have added the row so break the loop
              break;
            }
            else{
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
                 //when this loop ends means we have traversed a complete level and in queue there are elements of next level
                 //so increase the depth
                 currDepth++;
            }
        }

        return root;
    }
};