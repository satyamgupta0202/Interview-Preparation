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
    
// Important
//for every node we determine maximum val in the left and right path it would give to us
// 
    
    int ans = INT_MIN;
    int height(TreeNode* root){
        
        if(root==NULL)return 0;
        int lh = max(0,height(root->left));
        int rh = max(0,height(root->right));
        
////Everytime we keep updating our ans as , lh+rh+root->val
        ans = max(ans , lh+rh+root->val);
        return max(lh,rh)+root->val;
   
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        height(root);
        return ans;
    }
};