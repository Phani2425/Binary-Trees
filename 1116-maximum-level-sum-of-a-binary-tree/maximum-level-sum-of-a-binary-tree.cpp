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

//  solution using BFS
class Solution {
public:

    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int minLvl = INT_MAX;
        int currLvl = 1;
        
        while(!q.empty()){
            int size = q.size();
            int sum = 0;  

            while(size--){

                TreeNode* temp = q.front();
                sum += temp->val;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

            }

             if(sum > maxSum){
               maxSum = sum;
               minLvl = currLvl;
            }
            currLvl++;
        }

        return minLvl;
    }
};

//  solution using DFS

//LEARNT:- IF A QUERSTION SEEMS THAT WE MUST HAVE TO SOLVE THIS USING BFS BUT YOU WANT OT DO THIS USING DFS THEN YOU HAVE TO CONSIDER ABOUT USING A DS LIKE MAP.
//WHY I AM SAYING THIS IS IN SUCH TYPE OF CASES WHERE IT SEEMS ONLY BFS CAN SOLEV THIS THERE WE NEED TO PERFORM SOME OPERATION AMONG ALL NODES IN A SINGLE LEVEL FOR WHICH WE HAVE TO COLLECT THEM AT ONNCE
//AND THIS IS POSIIBLE IN BFS ONLY AS WE USE QUEUE THERE. BUT IF WE WANT TO USE DFS THEN BHAI USE MAP OR SOMETHING LIKE THAT WHICH SHOWS BEHAVIOUR LIKE MAP I.E STORE SOME VALUE CORRESPONDING TO THE LEVEL NUMBER

//IN THIS WAY YOU CAN SOLEV THOSE TYPE OF QUESTIONS