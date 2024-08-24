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

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
       if (!root) {
           return NULL;
       }
       if (root->val == p || root->val == q) {
           return root;
       }

       TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
       TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

       if (leftN && rightN) {
           return root;
       }
       return leftN ? leftN : rightN;
    }

    bool findPath(TreeNode* node, int targetValue, string& path) {
        if (!node) {
            return false;
        }
        if (node->val == targetValue) {
            return true;
        }

        path.push_back('L');
        if (findPath(node->left, targetValue, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(node->right, targetValue, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string pathToSource = "", pathToDest = "";
        findPath(LCA, startValue, pathToSource);
        findPath(LCA, destValue, pathToDest);

        // Convert pathToSource to 'U'
        string result(pathToSource.length(), 'U');
        result += pathToDest;

        return result;
    }
};


//APPROACH:- 

//FOR FINDING SHORTEST PATH BETWEEN SOURCE AND DESTINATION NODE THE MOST OPTIMISED WAY IS TO FINDOUT THE LCA{LOWEST COMMON ANCESTOR} OF BOTH AND THEN FINDING THE PATH BETWWEN THEM
//I KNOW HOW TO FIND LCA SO LETS DO THAT WITH THE HELP OF A HELPER FUNCTION

//AFTER GETTING THE ADDRESS OF LCA:-

//WE WILL FIND PATH FROM LCA TO SOURCE and LCA TO DESTINATION