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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st1;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            res.push_back(root->val);
            if(root->left)
                st1.push(root->left);
            if(root->right)
                st1.push(root->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//     vector<int> postorderTraversal(TreeNode* root) {
        
// //         using two stack 
//         vector<int>ans;
//         stack<TreeNode*>s1,s2;
//         if(root==NULL)return ans;
        
//         s2.push(root);
        
//         while(!s2.empty()){
//             auto curr = s2.top();
//             s2.pop();
//             s1.push(curr);
//             if(curr->left){
//                 s2.push(curr->left);
//             }
//             if(curr->right){
//                 s2.push(curr->right);
//             } 
//         }
//         while(!s1.empty()){
//             ans.push_back(s1.top()->val);
//             s1.pop();
//         }
//         return ans;
//     }
// };

// Ierative approach
// vector<int>ans;
//     void postorder(TreeNode* root){
//         if(root==NULL){
//             return;
//         }   
//         postorder(root->left);
//         postorder(root->right);
//         ans.push_back(root->val);
//     } 
//     vector<int> postorderTraversal(TreeNode* root) {
//         postorder(root);
//         return ans;
//     }
// };