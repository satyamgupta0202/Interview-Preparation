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
    
    TreeNode*build(vector<int>&preorder,int preStart,int preEnd , vector<int>&inorder,int inStart,int inEnd){
        
        if(preStart>preEnd || inStart>inEnd)return NULL;
        
        int indx = mp[preorder[preStart]];
        int nxt = indx-inStart;
        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = build(preorder,preStart+1,preStart+nxt , inorder,inStart,indx-1);
        root->right = build(preorder,preStart+nxt+1,preEnd,inorder,indx+1,inEnd);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
         
        TreeNode* root = build(preorder,0,n-1,inorder,0,n-1);
        return root;
        
    }
};