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
    
    void solve(TreeNode* root , int val,TreeNode* temp){
        
        if(root==NULL){
            if(temp->val > val){
                temp->left = new TreeNode(val);
                return;
            }
            else{
                temp->right = new TreeNode(val);
                return ;
            }
        }
        
        
        if(root->val > val){
            temp = root;
            solve(root->left,val,temp);
        }else{
            temp = root;
            solve(root->right,val,temp);
        }
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL){
            TreeNode* ans = new TreeNode(val);
            return ans;
        }
        TreeNode* ans = root;
        TreeNode* temp;
        solve(root,val,temp);
        return ans;
     
    }
};