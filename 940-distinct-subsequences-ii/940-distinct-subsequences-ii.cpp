class Solution {
public:
long long  mod = 1e9+7;
long  solve(string &s) {

    unordered_map<char,int>mp;
    for(char ch = 'a' ; ch<='z' ;ch++){
        mp[ch] = -1;
    }

    int n = s.size();
    long long dp[n+1];

    dp[0]=1;
    int ok=0;

    for(int i=1;i<=n;i++){

        dp[i] = (dp[i-1]* (2%mod))%mod;
        char k = s[i-1];
        if(mp[k]!=-1){
           ok++;
            dp[i] = (dp[i]%mod -  dp[mp[k]-1]%mod +mod)%mod;

        }

        mp[k]=i;


    }

 return dp[n]-1;


}
    long long distinctSubseqII(string s) {
       return  solve(s);
    
    }
};