class Solution {
public:
    int dp[2001][2001];
    
    int solve(string &s1,string &s2 , int n1 ,int n2 , int i, int j){
        
        if(i==n1 || j==n2){
            int sum = 0;
            for(int x=i;x<n1;x++)sum+=int(s1[x]);
            
            for(int x=j;x<n2;x++)sum+=int(s2[x]);
            
            return sum;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i] == s2[j]){
            return solve(s1,s2,n1,n2,i+1,j+1);
        }
        
            int a1 = int(s1[i]) + solve(s1,s2,n1,n2,i+1,j);
            int a2 = int(s2[j]) + solve(s1,s2,n1,n2,i,j+1); 
            return dp[i][j]= min(a1,a2);   
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int n1=s1.size(),n2=s2.size();
        return solve(s1,s2,n1,n2,0,0);        
    }
};