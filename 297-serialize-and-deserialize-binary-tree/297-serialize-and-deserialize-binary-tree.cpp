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
        
        string s = "";
        if(root==NULL)return s;
        queue<TreeNode*>q;
        q.push(root);
        
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            if(node == NULL)s.append("#,");
            
            else s.append(to_string(node->val)+',');
            
            if(node!= NULL){
                q.push(node->left);
                q.push(node->right);
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