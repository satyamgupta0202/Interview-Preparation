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
    using node = TreeNode;
    vector<int>ans;
    stack<node*>s;
    node *temp=root;
    while(true)
    {
        if(temp!=NULL){
        s.push(temp);
        temp=temp->left;
        }
        else
        {
            if(s.size()==0)  break;
            temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            temp=temp->right;
        }
    }
    return ans;        
    }
     
};



// class Solution {
// public:
//      vector<int>ans;
    
//     void inorder(TreeNode* root){
//         if(root==NULL){
//             return;
//         }
        
//         inorder(root->left);
        
//         ans.push_back(root->val);
        
//         inorder(root->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorder(root);
//         return ans;
//     }
// };