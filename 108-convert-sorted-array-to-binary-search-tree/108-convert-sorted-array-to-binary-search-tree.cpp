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
    
    TreeNode* build (vector<int>&nums, int start , int end) {
        
        int mid = (start+end)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        if(start>end){
            return  NULL;
        }
        
        
        temp->left = build(nums,start,mid-1);
        temp->right=build(nums,mid+1,end);
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        int nn = nums.size();
        int mid = nn/2;
        
        
        TreeNode* root = build(nums,0,nn-1);
        return root;
        
        
    }
};