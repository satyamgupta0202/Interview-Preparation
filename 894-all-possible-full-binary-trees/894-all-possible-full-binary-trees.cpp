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
    
    vector<TreeNode*> solve(int n )
    {
        
        if(n==1)return {new TreeNode(0)};
        
        vector<TreeNode *> trees;
        
        n--;
        
        vector<TreeNode *>left,right;
        
        for(int i=1;i<n;i=i+2)
        {
            left = solve(i);
            right =solve(n-i);
            
            for(auto l: left )
            {
                for(auto r: right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                     trees.push_back(root); 
                }
            }
           
            
        }
        return trees; 
    }
   
    
    vector<TreeNode*> allPossibleFBT(int n)
    {
      
       if(n==1)return {new TreeNode(0)};
        
       if(n<3)return {};
        
       if(n%2==0)return {};
        
       if(n==3)return {new TreeNode(0,new TreeNode(0), new TreeNode(0))};
    
       return solve(n);
        
    
        
    }
    
};