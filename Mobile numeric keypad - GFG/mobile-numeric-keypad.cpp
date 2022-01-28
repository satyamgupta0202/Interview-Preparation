// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int n){
	    
        long long dp[n+1][10];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=10;i++){
            dp[1][i]=1;
        }

        for(int i=2;i<=n;i++){

            for(int j=1;j<=10;j++){

                if(j==1){
                  dp[i][j] = dp[i-1][j] +  dp[i-1][2]+ dp[i-1][4];
                }

                 if(j==2){
                  dp[i][j] = dp[i-1][j] +  dp[i-1][1]+ dp[i-1][3] + dp[i-1][5];
                }
                 if(j==3){
                  dp[i][j] = dp[i-1][j] +  dp[i-1][2]+ dp[i-1][6] ;
                }
                 if(j==4){
                  dp[i][j] = dp[i-1][j] +  dp[i-1][1]+ dp[i-1][7] + dp[i-1][5];
                }
                 if(j==5){
                  dp[i][j] = dp[i-1][j] +  dp[i-1][2]+ dp[i-1][4] + dp[i-1][6]+dp[i-1][8];
                }
                if(j==6){
                      dp[i][j] = dp[i-1][j] +  dp[i-1][3]+ dp[i-1][5] + dp[i-1][9];
                }
                if(j==7){
                   dp[i][j] = dp[i-1][j] +  dp[i-1][4]+ dp[i-1][8] ;
                }
                if(j==8){
                    dp[i][j] = dp[i-1][j] +  dp[i-1][7]+ dp[i-1][5] + dp[i-1][9]+dp[i-1][10];
                }
                if(j==9){
                    dp[i][j] = dp[i-1][j] +  dp[i-1][6]+ dp[i-1][8] ;
                }
                if(j==10){
                    dp[i][j] = dp[i-1][j] +  dp[i-1][8];
                }

            }

        }

        long long ans=0;
        for(int i=1;i<=10;i++){
            ans+=dp[n][i];
        }
        return ans;

        
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends