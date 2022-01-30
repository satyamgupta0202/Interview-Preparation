/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    map<TreeNode* , TreeNode*>mp;
    
    void createParent(TreeNode* root) {
        
        if(root==NULL)return ;
        
        if(root->left){
            mp[root->left]=root;
            createParent(root->left);
        }
        
        if(root->right){
            mp[root->right]=root;
            createParent(root->right);
        }    
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         
        queue<TreeNode*>q;
        createParent(root);
        q.push(target);
        int c=0;
        map<TreeNode* , int>vis;
        vis[target]=1;
        if(k==0){
            return {target->val};
        }
        while(!q.empty()){
            
            int m = q.size();
            while(m--){
                
                auto curr = q.front();
                q.pop();
                
                if(curr->left && vis[curr->left]==0){
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right && vis[curr->right]==0){
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(mp[curr] && vis[mp[curr]]==0){
                    q.push(mp[curr]);
                    vis[mp[curr]]=1;
                }  
            }
            c++;
            if(c==k){
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    ans.push_back(curr->val);
                }
                return ans;
            }
        }
        
        return {};
    }
};