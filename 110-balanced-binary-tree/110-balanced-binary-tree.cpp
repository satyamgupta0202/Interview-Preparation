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
    bool ok=true;
    int height(TreeNode* root) {
        
        if(root==NULL)return 0;
        
        return 1+ max( height(root->left) , height(root->right));
        
    }
    
    void check(TreeNode* root){
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1){
            ok = false;
        }
    }
    
    void preorder(TreeNode* root){
        
        if(root==NULL){
            return;
        }
        check(root);
        preorder(root->left);
        preorder(root->right);   
    }
    
    bool isBalanced(TreeNode* root) {
        
//         travel and check
        
        preorder(root);
        return ok;
    }
};