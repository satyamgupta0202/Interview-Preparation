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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* temp = root;
        while(true){
            
            if(temp){
                st.push(temp);
                temp=temp->left;
            }
            else{
                if(st.size()==0)break;
                temp = st.top();
                ans.push_back(temp->val);
                st.pop();
                temp=temp->right;
            }
            
        }
        return ans;
    }   
};


