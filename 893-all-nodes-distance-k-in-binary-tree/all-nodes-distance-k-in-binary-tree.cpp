/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     unordered_map<TreeNode*, TreeNode*> mp;
     void inorder(TreeNode* root){
        if(!root) return ;

        //jadi mora left achi tahale kahide left ra parent heli mu
        //so jadi left node by chnace target heithiba then mate bi queue re push kariki explore kariba because semiti kale tame target ru upwards bhi tarvel kari pariba
        if(root->left){
            mp[root->left] = root;
        }

        // jadi mora right achi then map re save karide ki right ra prent hauchi mu
        if(root->right){
            mp[root->right] = root;
        }
        
        inorder(root->left);
        inorder(root->right);

     }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        inorder(root);

        queue<TreeNode*> q;

        // because i will start the level order tarversal from the target only
        q.push(target);

        // dekh jetebele dry run kariki dekhibu setebele tu paibu ki as we are pushing left,right and also parent of a node then there is a chnace that already explored node might get pushed again into the queue... so to avaoid that we will maintain a visited map 
        unordered_map<TreeNode*,int> visited;

        // this will indicate what is the current distance between the target node and thhe nodes present in the queue
        int currDistance = 0;

        vector<int> ans;

        while(!q.empty()){
            int size = q.size();
            // previously i puted this in end of inner loop but then i shifted it to above that but why??? what was the issue there??? think it ...what if k is 0 then how ans will be find??? think deeply
             if(currDistance == k){
               while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node->val);
               }
               break;
            }
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = 1;
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                }
                if(temp->right && visited[temp->right] != 1){
                    q.push(temp->right);
                }
                if(mp.find(temp) != mp.end() && visited[mp[temp]] != 1){
                    q.push(mp[temp]);
                }

            }


            currDistance++;
        }

        return ans;
        
    }
};