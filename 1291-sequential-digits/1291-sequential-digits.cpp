class Solution {
public:
    
    int check(int n){
        int c=0;
        
        while(n){
            c++;
            n/=10;
        }
        
        return c;
    }
    vector<int>ans;
    vector<int> sequentialDigits(int low, int high) {
        
        int l = check(low);
        int h = check(high);
        long curr = 0;
        for(int k=l ; k<=h;k++){
            curr=0;
            for(int i=1;i<=9;i++){
                
                curr = (curr*10) + i;
                
                if(check(curr)==k){
                    
                    if(curr>=low && curr<=high){
                        ans.push_back(curr);
                    }
                    curr %= int(pow(10, k-1));
                }
                
                
            }
            
            
        }
        
        return ans;
    }
};