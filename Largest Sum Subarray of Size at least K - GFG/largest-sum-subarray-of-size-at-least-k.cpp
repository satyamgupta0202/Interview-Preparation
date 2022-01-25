// { Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends




void solve(long long int a[] , long long int n , long long int k,int dp[]){
    dp[0]=0;
    long long int curr = a[0] , ans = a[0] , p=0,q=0;
    dp[0+1]=a[0];
    for(int i=1;i<n;i++){
        
        if(curr<0){
            curr=a[i];
        }
            else{
                curr+=a[i];
            }
        dp[i+1]=curr;    
    }
//   cout<<"lol"<<endl;
//     for(int i=0;i<=n;i++){
//         cout<<dp[i]<<" ";
//     }
//     cout<<"lol"<<endl;
}

long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    int dp[n+1];
     solve(a,n,k,dp);
     int ans = INT_MIN;
     int i=0,j=0;
     int sum=0;
     while(j<n){
         
         while(j-i+1<k){
             sum+=a[j];
             j++;
         }
         
         if(j-i+1==k){
             
             sum = sum+a[j];
             ans = max(ans , max(sum+dp[i],sum));
           //  cout<<"ans"<<" "<<i<<" "<<ans<<endl;
             sum = sum - a[i];
             i++;
             j++;
         }
     }
     
     return ans;
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
}