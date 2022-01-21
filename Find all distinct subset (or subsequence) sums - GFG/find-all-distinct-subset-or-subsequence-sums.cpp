// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

vector<int>ans;

void solve(vector<int>&nums , int n , int sum){
    
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=sum;i++)dp[0][i]=false;

    for(int i=0;i<=n;i++)dp[i][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    
    

    for(int i=0;i<=sum;i++){
        if(dp[n][i])ans.push_back(i);
    }



}
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	int sum = 0;
    int n = nums.size();

    for(int i=0 ; i<n ; i++){
        sum+=nums[i];
    }
    

    solve(nums,n,sum);
    //for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return ans;

	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
  // } Driver Code Ends