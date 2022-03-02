/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
      string serialize(TreeNode* root) {
        
        queue<TreeNode*>q;
        string s = "";
        if(root==NULL)return s;
        q.push(root);
        
        while(!q.empty()){
            
            auto curr = q.front();q.pop();
            
            if(curr==NULL){
                s = s+"#,";
            }
            else{
                s+=to_string(curr->val)+",";
            }  
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }     
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        queue<TreeNode*>q;
        TreeNode* root;
        string str;
        if(data.size()==0)return NULL;
        stringstream s(data);
        getline(s,str,',');
        
         if(str!="#"){
             root=new TreeNode(stoi(str));
         }else{
             return NULL;
         }
        q.push(root);
        while(!q.empty()){
          auto node = q.front();q.pop();
           getline(s,str,',');
            if(str!="#"){
             TreeNode* l = new TreeNode(stoi(str));
               node->left = l;
               q.push(node->left);
            }else{
               node->left = NULL;
            }
            
             getline(s,str,',');
            if(str!="#"){
             TreeNode* r = new TreeNode(stoi(str));
               node->right = r;
                q.push(node->right);
            }else{
               node->right = NULL;
            }   
            
         }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));