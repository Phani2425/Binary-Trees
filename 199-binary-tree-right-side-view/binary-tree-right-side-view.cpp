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

    int findHeight(TreeNode* root){

        if(!root)return 0;

        return (1+max(findHeight(root->left),findHeight(root->right)));

    }
    void helperFun(TreeNode* root,int currLevel,vector<int>&ans){
        if(!root) return;

        ans[currLevel] = root->val;
        helperFun(root->left,currLevel+1,ans);
        helperFun(root->right,currLevel+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {

        // find the height of the tree and we will have that much level so that we can create ans vector of that size
        int height = findHeight(root);
        vector<int> ans(height);
        helperFun(root,0,ans);
        return ans;
        
    }
};

// the problem can be solevd in both dfs and bfs appraoch the bfs appraoch i squite easy which is simple levcel oreder traversal and at each level we just have to get the las element and at the end when all levels atre traversed then we will have the right side view of the tree

// But the DFS traversal twchnique is little tricky and have to remebered by which we solved it here

//the logic behind this is:- if every node have information about which level they belong to and we push each node into their respective index{equal to their level number} then whiile traversing it recursively then the node which will be in the index at the end of traversal that will must be the end elemnt of that level