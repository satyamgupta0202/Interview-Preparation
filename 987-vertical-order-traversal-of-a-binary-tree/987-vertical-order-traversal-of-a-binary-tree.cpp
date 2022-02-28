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

// in vertical order traversal : map<int, map<int,multiset<int>>>
// end for(auto it: mp) --> it.second--> 

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        
        map<int,map<int,multiset<int>>>mp;
        
        queue<pair<int,TreeNode*>>q;
        
        q.push({0,root});
        int y=0;
        
        while(!q.empty()) {
            
            int m = q.size();
            
            while(m--){
                
                auto x = q.front().first;
                auto curr = q.front().second;
                q.pop();
                mp[x][y].insert(curr->val);
                
                if(curr->left){
                    q.push({x-1,curr->left});
                }
                if(curr->right){
                    q.push({x+1,curr->right});
                }
            }
            
            y++;     
        }
        
        for(auto it: mp){
            
            vector<int>v;
            
            for(auto lol : it.second){
               v.insert(v.end(),lol.second.begin(),lol.second.end());  //lol.second-->set
            }
            ans.push_back(v);
            
        }
       return ans; 
        
    }
};