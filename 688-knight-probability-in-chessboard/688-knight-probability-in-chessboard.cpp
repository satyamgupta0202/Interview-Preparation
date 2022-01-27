class Solution {
public:
    double out=0;
    double in= 0;
 
    double solve(int n , int k , int i,int j , int m, vector<vector<vector<double>>>&dp){
        
        if(i<0 || j<0 || i>=n || j>=n ){
            out++;
            return 0.0;
        }
        if(m==k){
            in++;
            return 1.0 ;
        }
        
        if(dp[i][j][m]!= -1)return dp[i][j][m];
        
        return dp[i][j][m] =  ((
        solve(n,k,i+2,j+1,m+1,dp)+
        solve(n,k,i-2,j+1,m+1,dp)+
        solve(n,k,i+1,j+2,m+1,dp)+
        solve(n,k,i-1,j+2,m+1,dp)+
        solve(n,k,i+2,j-1,m+1,dp)+
        solve(n,k,i-2,j-1,m+1,dp)+
        solve(n,k,i+1,j-2,m+1,dp)+
        solve(n,k,i-1,j-2,m+1,dp))/8.0) ;
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        
       // memset(dp,-1.0 ,sizeof(dp)); 
        vector<vector<vector<double>>> dp(30, vector<vector<double>>(30, vector<double>(105, -1)));
        return solve(n,k,row,column,0,dp);
        cout<<out<<" "<<in<<endl;
        double res = (double)((in)/(in+out));
        return res;   
    }
};