/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* ansNode;

   int findAncestorNode(TreeNode* root,int p,int q){
    //base case
    if(!root){
        return 0;
    }
    if(root->val == p || root->val == q){
        return 1;
    }

    //recursive case
    int leftSide = findAncestorNode(root->left,p,q);
    int rightSide = findAncestorNode(root->right,p,q);

    //as only target nodes having value p and q will return 1 hence the node which will get 1 from both left and right side will be obviosly the lowest common ancestor of both nodes
    if(leftSide == 1 && rightSide == 1){
        ansNode = root;
        return 0;
    }
    if(leftSide == 0 && rightSide==0){
        return 0;
    }
    else{
        return 1;
    }
   }

   int height(TreeNode* node){
    if(!node){
        return 0;
    }
    return 1+max(height(node->left),height(node->right));
   }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findAncestorNode(root,p->val,q->val);

        if(!ansNode){
            int heightOfp = height(p);
            int heightOfq = height(q);
            if(heightOfp > heightOfq){
                return p;
            }
            else{
                return q;
            }
        }
        return ansNode;
    }
};