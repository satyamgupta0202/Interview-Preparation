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

//Method 1
/**

class Solution {
public:
    vector<int>ans;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int n =ans.size();
        for(int i=1;i<n;i++){   
            if(ans[i]<=ans[i-1]){
                return false;
            }
        }
        return true;
    }
};

**/



bool check(TreeNode* root , long mi , long ma){
    
    if(root==NULL ){
        return true;
    }
    if(root->val>=ma || root->val<=mi)return false;
    return (check(root->right,root->val,ma) && check(root->left,mi,root->val));
   
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //node , min , max
          return check(root,LONG_MIN , LONG_MAX);  
    }
};