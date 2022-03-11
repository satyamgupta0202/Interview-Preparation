class Solution {
public:
    
    string solve(string s1 , string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
                }
            }
        }
        
        string temp ="";
        
        int i=n1 , j=n2;
        
        while(i>0 && j>0)
        {
            
            if(s1[i-1]==s2[j-1])
            {
                temp.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                {
                    temp.push_back(s2[j-1]);
                    j--;
                }
                else
                {
                    temp.push_back(s1[i-1]);
                    i--;
                }
            }  
        }
        
        while(i)
        {
            temp.push_back(s1[i-1]);
            i--;
        }
        
          while(j)
        {
            temp.push_back(s2[j-1]);
            j--;
        }
        
        
        cout<<temp<<endl; 
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
    string temp1 = "" , temp2 = "";
    
    
    
    
    string shortestCommonSupersequence(string str1, string str2) 
    {
        return solve(str1,str2);
        
    }
};