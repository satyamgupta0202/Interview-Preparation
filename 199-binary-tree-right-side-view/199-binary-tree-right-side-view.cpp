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
    vector<int> rightSideView(TreeNode* root) {
        //left and right view is basically level order traversal
        map<int,int>mp;
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int y=0;
        
        while(!q.empty()){
            
            int m = q.size();
            while(m--){
                
               auto curr = q.front();
               q.pop();
               mp[y]=curr->val; 
                
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

           }
            y++;
       }
            
        for(auto it: mp){
            ans.push_back(it.second);
        }
            
    return ans;
        
        
    }
};