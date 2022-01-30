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
    
    TreeNode *solve(vector<int>&pre,int preStart , int preEnd , vector<int>&in , int inStart , int inEnd){
        
        if(preStart>preEnd || inStart>inEnd)return NULL;
        
        TreeNode* root = new TreeNode(pre[preStart]);
        int indx = mp[pre[preStart]];
        int nxt = indx-inStart;
        root->left = solve(pre,preStart+1,preStart+nxt,in , inStart,indx-1);
        root->right=solve(pre,preStart+nxt+1,preEnd,in,indx+1,inEnd);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
         int n = in.size();
         TreeNode* root = solve(pre,0,n-1,in,0,n-1);
         return root;
    }
};