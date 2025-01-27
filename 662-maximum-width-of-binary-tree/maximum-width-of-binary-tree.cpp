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

//i learnt how to define type here
//basically i am renaming the unsigned long long to ll
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {

      ll maxWidth = 0;
       queue<pair<TreeNode*,ll>>q;
       q.push({root,0});

       while(!q.empty()){
        int size = q.size();
        ll firstIndex = q.front().second;
        ll lastIndex = q.back().second;
        maxWidth = max(maxWidth,(lastIndex-firstIndex+1));

        while(size--){
            pair<TreeNode*,ll> temp = q.front();
            q.pop();
            if(temp.first->left){
                q.push({temp.first->left, 2*(temp.second)+1});
            }

            if(temp.first->right){
                q.push({temp.first->right, 2*(temp.second)+2});
            }

        }
       }

return maxWidth;
        
    }
};


// Understanding unsigned long long int vs signed long long int in C++
// unsigned long long int:

// This is an unsigned integer type.
// It can only store non-negative integers (0 and positive values).
// The range is larger because it doesn’t reserve a bit for the sign.
// Typical range: 0 to 2^64 - 1 (on most systems, up to 18,446,744,073,709,551,615).
// signed long long int (or just long long int):

// This is a signed integer type, which can store both negative and positive integers.
// It reserves one bit for the sign (+ or -), so the range is smaller than its unsigned counterpart.
// Typical range: -2^63 to 2^63 - 1 (on most systems, from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807).
// long long:

// By default, long long is the signed version.
// Writing long long is equivalent to signed long long int.