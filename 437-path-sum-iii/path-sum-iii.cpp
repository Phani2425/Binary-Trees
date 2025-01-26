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
int count=0;

    void helperFun(TreeNode* root,int & targetSum,long long int & sum,map<long long int,int>& mp){
        if(!root) return;

        sum+=root->val;
       

        if(mp.find(sum-targetSum) != mp.end()){
            count+=mp[sum-targetSum];
        }

         mp[sum]++;

        helperFun(root->left,targetSum,sum,mp);
        helperFun(root->right,targetSum,sum,mp);

        // backtracking
        mp[sum]--;
        sum-=root->val;

    }

    int pathSum(TreeNode* root, int targetSum) {
    long long int sum = 0;
    map<long long int,int>mp;
    mp[0]++;
    helperFun(root,targetSum,sum,mp);
    return count;
      
    }
};