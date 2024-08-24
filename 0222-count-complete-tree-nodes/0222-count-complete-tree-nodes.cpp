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

    //basically it used to find the left side height and takes a t.c of O(h) and it will be O(logn) if the tree is perfect binary tree [in PBT h=logn]
    int getLeftHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+getLeftHeight(root->left);
    }

    
    //basically it used to find the right side height and takes a t.c of O(h) and it will be O(logn) if the tree is perfect binary tree [in PBT h=logn]
        int getRightHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+getRightHeight(root->right);
    }

    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int LH = getLeftHeight(root);
        int RH = getRightHeight(root);

        //checking if the node having this LH and RH is a root of a perfect binary tree
        if(LH == RH){
            return pow(2,LH)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};