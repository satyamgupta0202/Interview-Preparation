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
    int maxDepth(TreeNode* root) {
        
        queue<TreeNode*>q;
        int cnt = 0;
        if(!root )return cnt;
        
        q.push(root);
        
        while(!q.empty()){
            
            int m = q.size();
            while(m--){
                auto it = q.front();
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            cnt++;   
        }
        return cnt;
        
    }
};
/**
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL)return 1;
        
        return 1+( max(maxDepth(root->left),maxDepth(root->right)));
        
    }
};
**/
