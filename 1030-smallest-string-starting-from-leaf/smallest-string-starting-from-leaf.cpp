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
    string smallestFromLeaf(TreeNode* root) {

        queue<pair<TreeNode*,string>> q;
        q.push({root,string(1,root->val+'a')});

        string ans="";

        while(!q.empty()){
           auto [node,path] = q.front();
           q.pop();
        //    jadi ei node leaf node heithae then
        if(!node->left && !node->right){
            if(ans == "" || ans > path){
                ans = path;
            }
        }

        if(node->left){
         q.push({node->left,string(1,node->left->val+'a').append(path)});
        }

         if(node->right){
         q.push({node->right,string(1,node->right->val+'a').append(path)});
        }

        }

        return ans;
        
    }
};

// APPROACH:-

// DFS APPROACH

// maintain a variable which will store the smallest  lexicographically string

// move from root to leaf and build  the path with backtracking -> either build it normally and then reverse it at last or just add new character in the starting of the path instead of end for which the path will be created in reverse order from begining itself

// then when ever you reach to a leaf node then just compare the path with the path stored in the variabble and store the smallest lexicographical path

// I learnt that two strings can be compared just as numbers

// BFS APPROACH

// it is little bit intresting as here we need to maintain all the paths starting from root to leaf even if we will traverse the tree level by level and this type of problems are important in ternms of how we approach to  solve this

// basically the idea is if a node is having a ceratin path from root then the left child will add its own character to that  path and hold the whole path , simmilar with the right child ...........in this way we can maintain all the path from root to leaf