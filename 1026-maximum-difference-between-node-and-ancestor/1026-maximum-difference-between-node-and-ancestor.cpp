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

    void DFShelper(TreeNode* node,int maxm,int minm,int& ans){
       if(!node){
        return;
       }

       //update the ans variable
       ans = max(ans, max( abs(node->val-maxm), abs(node->val-minm))); //VERY IMP CONCEPT THAT MAX CAN TAKE ONLY 2 ELEMENT SO WE HAD TO USE NESTED MAX()

       //now update the max and min
       maxm = max(maxm,node->val);
       minm = min(minm,node->val);

       //recursive call to these steps in left and right node
       DFShelper(node->left,maxm,minm,ans);
       DFShelper(node->right,maxm,minm,ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;//taken as 0 because a node can be considered as its own ancestor so in that case the maximum dif will be 0
        DFShelper(root,root->val,root->val,ans);//initialy max and min will be equal to data of root
        return ans;
    }
};

// The intuition behind the solution is that we can find the maximum difference by thoroughly searching through the tree. We do this using a depth-first search (DFS) algorithm, which will allow us to explore each branch of the tree to its fullest extent before moving on to the next branch.

// During the traversal, we keep track of the minimum (mi) and maximum (mx) values encountered along the path from the root to the current node. At each node, we calculate the absolute difference between root.val and both the mi and mx values, updating the global maximum ans if we find a larger difference.

// The core idea is to track the range of values (minimum and maximum) on the path from the root to the current node because this range will allow us to compute the required maximum absolute difference at each step. By the time we complete our traversal, we will have examined all possible pairs of ancestor and descendant nodes and thus found the maximum difference.

// To implement this, we use a recursive helper function dfs(root, mi, mx) that performs a depth-first search on the binary tree. The mi and mx parameters keep track of the minimum and maximum values respectively, seen from the root to the current node. The function also updates a nonlocal variable ans, which keeps track of the maximum difference found so far.

// Finally, we initiate our DFS with the root node and its value as both the initial minimum and maximum, and after completing the traversal, we return the value stored in ans, which will be the maximum ancestor-difference that we were tasked to find.

// Learn more about Tree, Depth-First Search and Binary Tree patterns.

// Solution Approach
// The solution to this problem involves a recursive depth-first search (DFS) algorithm to traverse the binary tree. The critical aspect of the approach is to maintain two variables, mi and mx, to record the minimum and maximum values found along the path from the root node to the current node.

// Here is a step-by-step breakdown of the implementation details:

// Define a recursive helper function dfs(root, mi, mx) that will be used for DFS traversal of the tree.
// If the current root is None, which means we've reached a leaf node's child, we return, as there are no more nodes to process in this path.
// The helper function is designed to continuously update a nonlocal variable ans, which holds the maximum absolute difference found.
// At each node, we compare and update ans with the absolute difference of the current node's value root.val with both the minimum (mi) and maximum (mx) values seen so far along the path from the root.
// We perform this comparison using max(ans, abs(mi - root.val), abs(mx - root.val)).
// After updating ans, we also update mi and mx for the recursive calls on the children nodes, setting mi to min(mi, root.val) and mx to max(mx, root.val). This ensures that as we go deeper into the tree, our range [mi, mx] remains updated with the smallest and largest values seen along the path.
// Recursive calls are then made to continue the DFS traversal on the left child dfs(root.left, mi, mx) and the right child dfs(root.right, mi, mx) of the current node.
// The main function initializes the variable ans to 0 and then calls dfs(root, root.val, root.val). We start with both mi and mx as the root's value, since initially, the root is the only node in the path. The implementation leverages the default argument-passing mechanism in Python, where every child node receives the current path's minimum and maximum values to keep the comparison going.

// After the completion of the DFS traversal, the ans variable, which was kept up-to-date during the traversal, will contain the final result—the maximum difference. The function finally returns ans.

// The primary data structure used in this implementation is the binary tree itself. No additional data structures are needed because the recursion stack implicitly manages the traversal, and the updating of minimum and maximum values is done using integer variables. This efficient use of space and recursive traversal makes it a neat and effective solution.

// I WAS ALSO THINKING THAT WHY CANT I DO IT IN BOTTOM UP APPROACH... MEANS THE SAME STEPS JUST I WILLL DO IT IN BOTTOM UP APPROACH [I WILL TRAVERSE TILL THE LEAF NODE FROM THERE I WILL PASS MIN AND MAX VALUE TO IT'S ANCESTOR TILL ROOT NODE REACHES AND AT EACH NODE UPDATE ANS FIRST AND THEN UPDATE MIN AND MAX]
// BUT THIS WILL NOT WORK BECUSE IN TOP DOWN APPROACH THROUGH OUT THE PATH WE MAINTAIN A MIN AND MAX VALUE AND UPDATE THEM AT EACH NODE BUT IF WE TRY TO DO IT IN BOTTOM UP APPROACH THEN IF A NODE WILL HAVE 2 CHILDREN THEN BOTH OF THEM WILL RETURN TWO DIFFERENT SETS OF MIN AND MAX VALUE AND IT WILL INCRESE THE COMPLEXITY OF PROBLEM .....THAT IS WHY WE USE TOP DOWN APPROACH

// AND THIS TOP DOWN APPROACH WILL ALSO WORK REALLY WELL WHEN IT HAS ASKED THAT THE ANCESTER NODE MUST BE GREATER THAN OR EQUALS TO THE DECENDENT NODE AND NOW CALCULATE THE MAXIMUM POSSIBLE DIFFERENCE BETWEEN THEM
