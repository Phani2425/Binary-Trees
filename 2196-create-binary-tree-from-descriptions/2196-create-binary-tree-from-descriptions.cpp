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
    TreeNode* findHead(vector<vector<int>>& descriptions, unordered_map<int, TreeNode*>& nodeMap) {
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int child = desc[1];
            children.insert(child);
        }

        for (auto& desc : descriptions) {
            int parent = desc[0];
            if (children.find(parent) == children.end()) {
                // This parent is not a child of any node, so it's the root
                return nodeMap[parent];
            }
        }

        return nullptr; // Should never reach here as input is guaranteed to be a valid tree
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap; // Map to store nodes by their values

        // Build the tree
        for (int i = 0; i < descriptions.size(); i++) {
            int parentVal = descriptions[i][0];
            int childVal = descriptions[i][1];
            bool isLeft = descriptions[i][2] == 1;

            if (!nodeMap[parentVal]) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            if (!nodeMap[childVal]) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }
        }

        // Find and return the head (root) of the tree
        return findHead(descriptions, nodeMap);
    }
};

