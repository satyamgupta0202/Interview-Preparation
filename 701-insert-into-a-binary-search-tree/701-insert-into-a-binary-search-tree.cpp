class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp = new TreeNode(val);
        TreeNode* ans = root;
        if(root == NULL){
            root = temp;
            return root;
        }
        
        while(root){
            
            if(root->val > val){
                if(root->left == NULL){
                    root->left = temp;
                    break;
                }
                root=root->left;
            }
            else{
                if(root->right == NULL){
                    root->right = temp;
                    break;
                }
                root=root->right;
            }
            
        }
        return ans;
        
    }
};