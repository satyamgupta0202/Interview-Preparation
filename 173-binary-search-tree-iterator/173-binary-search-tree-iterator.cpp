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
class BSTIterator {
public:
    
    stack<TreeNode*>st;
    
    void pushAll(TreeNode* root)
    {
           while(root)
           {
               st.push(root);
               root = root->left;
           }
    }
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        
        TreeNode* temp = st.top();
        st.pop();
        if(temp->right)
        {
            pushAll(temp->right);
        }
        
        return temp->val;
    }
    
    bool hasNext() 
    {
        return st.size()!=0;
    }
};




/**
class BSTIterator {
public:
    
    stack<TreeNode*>myStack;
    
    void pushAll(TreeNode* node ){
        
      while(node!=NULL){
          myStack.push(node);
          node=node->left;
      }    
    }
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(myStack.empty()){
            return false;
        }
        return true;
    }
};
**/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */