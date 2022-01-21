class Solution {
public:
int mod = 1e9+7;
int solve(string &s) {

    unordered_map<char,int>mp;
    for(char ch = 'a' ; ch<='z' ;ch++){
        mp[ch] = -1;
    }

    int n = s.size();
    long long dp[n+1];
    dp[0]=1;
   
    for(int i=1;i<=n;i++){

        dp[i] = (dp[i-1]*2)%mod;   
        char k = s[i-1];
        if(mp[k]!=-1){
            dp[i] = (dp[i] -  dp[mp[k]-1] +mod)%mod;      // substract the matching character -1 count

        }
        mp[k]=i;
    }

 return dp[n]-1;  //-1 for non empty sunsequence only
}
    
    int distinctSubseqII(string s) {
       return  solve(s);
    }
};