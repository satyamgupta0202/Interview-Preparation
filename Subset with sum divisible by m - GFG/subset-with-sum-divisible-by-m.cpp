// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
        
        bool solve(vector<int>nums , int m , int sum , int indx)
        {
            
            
            if(sum!=0 && sum%m == 0)return true;
            
            if(indx>=nums.size())
            {
                return false;
            }
            
            sum+=nums[indx];
            if(solve(nums,m,sum,indx+1))return true;
            sum-=nums[indx];
            if(solve(nums,m,sum,indx+1))return true;
            
            return false;
        }

		int DivisibleByM(vector<int>nums, int m)
		{
		    int sum = 0;
		    return solve(nums,m , sum , 0);
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends