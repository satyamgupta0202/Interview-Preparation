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
     map<int,int>mp;
    
    TreeNode* Build(vector<int>post,int postStart , int postEnd , vector<int>&inorder , int inStart,int inEnd){
        
        if(postStart>postEnd || inStart>inEnd)return NULL;
        
        int indx = mp[post[postEnd]];
        int nxt = indx-inStart;
        
        TreeNode* root = new TreeNode(post[postEnd]);
        
        root->left = Build(post, postStart, postStart+nxt-1  , inorder , inStart, indx-1 );
        
        root->right = Build(post , postStart+nxt , postEnd-1 , inorder , indx+1,inEnd);
        
        return root;
        
        
    }
    
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
         for(int i=0;i<n;i++){
             mp[inorder[i]] = i;
         }
         
         TreeNode* root = Build(postorder,0,n-1,inorder,0,n-1);
         return root;     
    }
};