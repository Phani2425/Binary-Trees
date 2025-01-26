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

    TreeNode* deleteNode(TreeNode* root,vector<TreeNode*>& ans,unordered_set<int>& set){
        if(!root) return NULL;

        root->left = deleteNode(root->left,ans,set);
        root->right = deleteNode(root->right,ans,set);

        if(set.find(root->val) != set.end()){
            //matlab ye wala node set me hai so we will delete it after pushing its left and right child to ans
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }else{
            return root;
        }
    }
 
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> ans;
        unordered_set<int>set;
        // instead of creating new variable for each value we can just do this
        for(int &data:to_delete){
            set.insert(data);
        }
        deleteNode(root,ans,set);

        //so here we are handling a edge case
        //to_delete re either the root node of tree thaipare or na bi thai pare

        //jadi thiba then seta upare recurive function re handle heijiba au end re seta delete heijba but jadi nathae that should be pushed to the ans right??? so we will do that here and handle the case when the root node is present in to_delete vector

        if(set.find(root->val) == set.end()){
            ans.push_back(root);
        }

        return ans;
        
    }
};