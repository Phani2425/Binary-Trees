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

    bool compareFunc(TreeNode* l , TreeNode* r){
        if(!l && !r){
            return true;
        }
        //jadi di ta jaka null nuhanti then either 2 ta jaka not null heithibe or either one of them is null
        //here we will check the 2nd condition
        if(!l || !r){
            //jadi 2 ta bhitaru only gotie null then semane symetric nuhanti so return false
            return false;
        }
        //controll came to here means that both are not null so lets compare its value 
        if(l->val != r->val){
            return false;
        }
        return compareFunc(l->left,r->right) && compareFunc(l->right,r->left);
    }

    bool isSymmetric(TreeNode* root) {
       return compareFunc(root->left, root->right); 
    }
};

//THIS QUESTION HAVE TWO WAYS TO SOLVE THIS:-

//WAY - 1

//CREATE A FUNCTION WHICH WILL TAKE A NODE AND MAKE INPLACE CHANGES TO FORM ITS MIRROR TREE OR BASICALLY REVERSE TREE
//THE PASS THE ROOT OF EITHER LEFT OR RIGHT SUBTREE AND REVERSE THAT
//THEN SIMPLY COMPARE THE BOTH SIDE SUBTREES LIKE YOU DO TO FIND OUT WHEATHER TWO TREES ARE SAME OR NOT
//IF THEY WOULD BE SYMETRICAL THEN UPON REVERSING ONE SIDE IT WILL LOOK SAME AS ANOTHER SIDE SO THE COMPARE FUNCTION WILL RETURN TRUE
//IF THE COMPARE FUNCTION RETURS FALSE THEN THAT MEANS THE TREE WERE NOT SYMMETRICAL THAT IS WHY AFTRE REVERSING A SIDE IT DIDN'T BECAME SAME AS OTHER SIDE

//WAY - 2

//IN THIS WAY NORMALLY WE WILL CREATE A RECURSIVE FUNCTION WHICH WILL COMPARE LEFT AND RIGHT SIDE OF THE ROOT NODE ON THE BASIS OF SOME CONDITIONS AS WRITTEN IN THE SUBMITTED CODE..........