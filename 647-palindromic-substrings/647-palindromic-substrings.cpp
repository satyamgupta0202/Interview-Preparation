class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        int cnt=0;
        memset(dp,false,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){

                    if(s[i]==s[j]){
                        if(j==i || j-i==1 || dp[i+1][j-1] ){
                            dp[i][j]=true;
                            cnt++;
                        }
                    }
            }
        }
        return cnt;
    }
};