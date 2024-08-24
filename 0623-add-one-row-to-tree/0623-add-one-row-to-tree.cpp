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




//SOLVING IT  USING DFS [BASICALLY RECURSION]

class Solution {
public:

    //a recursive function which will traverse each node and when a node turns out to be "curr" Node {as mentioned in question} {curr nodes are all the not null node which are at depth of [depth-1] :- means the nodes under which new row will be added}
    // it will add left and right child node with value "val" to the nodes left and right side
    void addOneRowHelper(TreeNode* node, int val, int depth, int currDepth){
        if(!node){
            return;
        }
        if(currDepth == depth-1){
            TreeNode* nodeLeft = new TreeNode(val);
                if(node->left){
                    nodeLeft->left = node->left;
                }
                //left ho na ho ye new node temp ke left me add hoga
                node->left = nodeLeft;
                //for creating right subtree root
                TreeNode* nodeRight = new TreeNode(val);
                if(node->right){
                    nodeRight->right = node->right;
                }
                ///similar for right
                node->right = nodeRight;
        }

        addOneRowHelper(node->left,val,depth,currDepth+1);
        addOneRowHelper(node->right,val,depth,currDepth+1);
    }


    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //edge case where depth is 1
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }

        addOneRowHelper(root,val,depth,1);

        return root;

    }
};
