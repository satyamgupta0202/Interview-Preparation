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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL || root==p || root==q)return root;
        
       TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        
        if(l==NULL)return r;
        if(r==NULL)return l;
        
        return root;
    }
};




//Greedy solution
/**
class Solution {
public:
    
  
    bool solve1(TreeNode* root , TreeNode* p , vector<TreeNode*>&path2){
        if(root==NULL)return false;
        
        path2.push_back(root);
        
        if(root==p){
            return true;
        }
        
        if(solve1(root->left,p,path2) || solve1(root->right,p,path2))return true;
        
        path2.pop_back();
        return false;
        
    }
      bool solve(TreeNode* root , TreeNode* p , vector<TreeNode*>&path1){
        if(root==NULL)return false;
        
        path1.push_back(root);
        
        if(root==p){
            return true;
        }
        
        if(solve(root->left,p,path1) || solve(root->right,p,path1))return true;
        
        path1.pop_back();
        return false;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        solve(root,p,path1);
        solve1(root,q,path2);
        
        for(int i=path1.size()-1;i>=0;i--){
            for(int j=path2.size()-1;j>=0;j--){
                if(path1[i] == path2[j]){
                    return path1[i];
                }
            }
        }
       return {};
    }
};
**/