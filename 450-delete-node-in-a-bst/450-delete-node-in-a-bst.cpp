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
    
    int left(TreeNode* root){
        
        int ans = root->val;
        
        while(root){
            ans = max(ans,root->val);
            root=root->right;
        }
        
        return ans;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)return root;
            
        if(root->val > key){
            root->left =  deleteNode(root->left,key);
        }
        
        else if(root->val< key){
            root->right =  deleteNode(root->right,key);
        }
        
        else{
            
            if(root->left == NULL && root->right==NULL){
                delete(root);
                return NULL;
            }
            else if(root->left==NULL){
                TreeNode* temp = root;
                root=root->right;
                delete(temp);
            }
            else if(root->right == NULL){
                TreeNode* temp = root;
                root=root->left;
                delete(temp);
            }
            
            else{
                
                int key = left(root->left);
                root->val = key;  
                root->left = deleteNode(root->left,key);
            } 
        }
        return root;
        
    }
};