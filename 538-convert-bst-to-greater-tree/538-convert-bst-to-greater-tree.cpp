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
    int c =0;
    void solve(TreeNode* root)
    {
        
        if(root->left==NULL && root->right==NULL)
        {
            c+=root->val;
            root->val = c;
            cout<<"leaf"<<c<<endl;
            return;
        }
        
        if(root->right && root->left)
        {
            
            solve(root->right);
            c+=root->val;
            root->val = c;
            solve(root->left);
            //c+=root->val;
            
        }
        
        
        else if(root->right)
        {
            solve(root->right);
            c+=root->val;
            root->val = c;
        }
        
        else
        {
            c+=root->val;
            root->val = c;
            solve(root->left);
            cout<<c<<" ";
        }
        
    }
    
    
    
    TreeNode* convertBST(TreeNode* root)
    {
        if(root==NULL)return NULL;
        solve(root);
        return root;
    }
};