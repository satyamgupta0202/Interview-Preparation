class Solution {
public:
    
    int solve(vector<int>&a , int f , int s){
           int n=a.size(),sum=0;
		// We are going to create two arrays for left max sum and right max sum
		/*
		There are going to be 2 cases;-
		1. Subarray of length f comes first followed by subarray of length s
		2. Subarray of length s comes first followed by subarray of length f
		 and then we will return the maximum sum got from both cases.*/
		
		
        int dp1[n],dp2[n];
		
		// Case 1.
		
        for(int i=0;i<n;i++)
        {
            if(i<f){
                sum+=a[i];
                dp1[i]=sum;
            }
            else
            {
                sum+=a[i]-a[i-f];
                dp1[i]=max(sum,dp1[i-1]);
            }
        }
        sum=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(i+s>=n)
            {
                sum+=a[i];
                dp2[i]=sum;
            }
            else
            {
                sum+=a[i]-a[i+s];
                dp2[i]=max(sum,dp2[i+1]);
            }
        }
        
        int ans=INT_MIN;
        for(int i=f-1;i<n-s;i++)
        {
            ans=max(ans,dp1[i]+dp2[i+1]);
        }
        return ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& a, int f, int s) {
    
        int a1 = solve(a,f,s);
        int a2 = solve(a,s,f);
        return max(a1,a2);
    }
};