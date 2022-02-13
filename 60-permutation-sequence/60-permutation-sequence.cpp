class Solution {
public:
    

   int fact[12];
    
    void fun()
    {
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=11;i++)
        {
            fact[i] = i*fact[i-1];
         }        
     }

    
    
    
    
    string getPermutation(int n, int k) {
        
        
        
        
        fun();
        
        
        string temp ="";
        for(int i=1;i<=n;i++){
            temp.append(to_string(i));
        }
        
        string ans = "";
        k--;
        for(int i=1;i<=n;i++)
        {
            int index = (k/fact[n-i]);
            
            ans.push_back(temp[index]);
            
            
             temp.erase(temp.begin()+index);
             cout<<temp<<endl;
             k=k-(index)*fact[n-i];
            
        }
        
        return ans;
        
        
    }
};




/** Method 1:
class Solution {
public:
    string getPermutation(int n, int k) {
        
        string temp = "";
        for(int i=1;i<=n;i++){
            temp.append(to_string(i));
        }
        
        for(int i=1;i<=k-1;i++){
            next_permutation(temp.begin(),temp.end());
        }
        
        return temp;
  
        
    }
};
**/