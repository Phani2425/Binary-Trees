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
//this can easily solevd using bfs tarversal so lets try it using dfs tarversal

//WAY-1 :-  WHERE I WILL FIRST FIND OUT THE HEIGHT OF THE TREE THEN I WILL CREATE A EVTOR OF SAME SIZE AS THE HEIGHT
//THEN WHILE TRAVERSING THE VECTOR I WILL UPDATE EACH INDEX WITH THE MAXIMMUM VALUE OF THAT LEVEL

//AND HERE I HAVE TO USE RECURSION IN DFS TO PROVIDE A LEVEL NUMBER I.E CURRLEVEL TO EACH NODE AND WE HAVE TO DO THIS SAME METHOD TWO TIMES......
//ONCE IS FOR FINDING HEIGHT AND ANOTHER TIMME IS FOR FINDING MAX IN EACH LEVEL

//IN WAY 2 I HAVE GENERATED A TRICKY WAY OF SOLVING THIS BY PERFORMING THIS OPERATION ONLY ONCE

    vector<int> ans;
    int maxHeight=0;
   

    void findHeight(TreeNode* root, int currLevel ){
        if(!root){
            return;
        }
        maxHeight = max(maxHeight,currLevel);

        findHeight(root->left,currLevel+1);
        findHeight(root->right,currLevel+1);
        
    }

    void helperFunction(TreeNode* root, vector<int>& ans, int currLevel){
        if(!root){
            return;
        }

        ans[currLevel] = max(ans[currLevel],root->val);

        helperFunction(root->left,ans,currLevel+1);
        helperFunction(root->right,ans,currLevel+1);
    }

    vector<int> largestValues(TreeNode* root) {

        findHeight(root,1);
        vector<int> ans(maxHeight, INT_MIN);
        helperFunction(root,ans,0);

        return ans;
        
    }
};


//WAY - 2

class Solution {
public:

    vector<int> ans;

    void helperFunction(TreeNode* root, vector<int>& ans, int currLevel){
        if(!root){
            return;
        }

        if(currLevel == ans.size()){//iska matlab me is level pe pehli baar aya hnu
          //so abhi compare nehi kar sakta so me direct abhi ka node ka value push kardunga
          ans.push_back(root->val);
        }
        else{//matlab is level pe me pehle bhi aa chuka hnu so isi level ka koi element ans ke "currLevel" index pe pada hoga
        //so ab comapre karke ans ko update  karenge kyu ki hame level ka max value chahiye
        ans[currLevel] = max(ans[currLevel], root->val);

        }

        helperFunction(root->left,ans,currLevel+1);
        helperFunction(root->right,ans,currLevel+1);
    }

    vector<int> largestValues(TreeNode* root) {

        helperFunction(root,ans,0);

        return ans;
        
    }
};
