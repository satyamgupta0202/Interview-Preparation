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
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans=0;
        int p=-1,q1=-1;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        
        while(!q.empty()){
            
            
            auto x = q.front().first;
            int m = q.size();
            
            for(int i=0;i<m;i++){
                
                 
                 auto curr = q.front().second;
                 auto w = q.front().first;
                 w = w-x;
                 cout<<w<<endl;
                 q.pop();
                 
                if(curr->left){
                    q.push({2*w,curr->left});
                }
                if(curr->right){
                    q.push({2*w+1,curr->right});
                }
                
                if(i==0){
                    
                    p=w;
                    
                }
                  if(i==m-1){
                    q1=w;
                }
                
                
            }
            ans = max(ans,q1+p+1);
            
        }
        
        return ans;
        
    }
};