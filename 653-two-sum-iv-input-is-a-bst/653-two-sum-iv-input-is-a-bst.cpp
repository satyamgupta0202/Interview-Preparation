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
    
    void preorder(TreeNode* root , vector<int>&v , int target) {
        
        if(root==NULL)return;
        preorder(root->left,v,target);
        v.push_back(root->val);
        preorder(root->right,v,target);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        preorder(root,v,k);
        if(v.size()<2)return false;
        
        for(int i=0;i<v.size();i++){
            
            int l = i+1;
            int h = v.size()-1;
            int res = k - v[i];
            while(l<=h){
                int mid = (l+h)/2;
                if(res==v[mid])return true;
                
                else if(v[mid]>res){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
                
            }
            
            
            
        }
        
        return false;
    }
};