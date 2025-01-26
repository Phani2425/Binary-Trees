// solution -1 (Bruet Force Approach)
class solution {
public:

Node * helperFun(vector<int>& temp,Node* root){
         if(!root) return NULL;
        helperFun(temp,root->left)
      helperFun(temp,root->right)
  if(!root->left && !root->right){
    temp.push_back(root->data);
    return NULL;
  }
  else{
    return root;
  }
           }

vector<vector<int>> findLeaf(Node* root){
  vector<vector<int>> ans;
vector<int> temp;
while(root){
root = helperFun(temp,root);
  ans.push_back(temp);
  temp.clear();
}

return ans;
}
   
}



// solution-2 (Optimised Approach)

class solution {
public:

Node * helperFun(map<int,vector<int>> & mp,Node* root) {
  if(!root) return 0;
  int left = helperFun(mp,root->left)
    int right = helperFun(mp,root->right)

  int height = max(left,right);
  mp[height].push_back(root->data);
  return 1+height;
           }

vector<vector<int>> findLeaf(Node* root){
  vector<vector<int>> ans;

  // instead of map we can use another way:- we can observe that the size of ans vector will be laways same as the height of the tree i.e if we keep removing leaf node form a tree then the no of times we need to remove them will be equal to [height+1] {if edge count is considered as height}  so we will directly create the ans vector of this much size
  // and then in recursive function we will directly oush elements into that  as in all type of DFS traversal for each node left is prefered before right so there wont be any problme around the order of leaf nodes which should be :- from left to right
map<int, vector<int>> mp;

helperFun(mp,root);

for (itr = mp.begin();itr != mp.end();itr++){

  ans.push_back(itr.second);
  
}


return ans;
}
   
}
