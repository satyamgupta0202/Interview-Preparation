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
    
    int lh(TreeNode* root){
        
        if(root==NULL)return 1;
        return 1+ lh(root->left);
        
    }
    
    int rh(TreeNode* root){
        
        if(root==NULL)return 1;
        
        return 1+ rh(root->right);
        
    }
    
    
    
    int countNodes(TreeNode* root) {
        
        if(root==NULL)return 0;
        
        int l = lh(root->left);
        int r = rh(root->right);
        
        if(l == r){
            return pow(2,l)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
        
        
    }
};