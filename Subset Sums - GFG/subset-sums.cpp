// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int>ans;
    
    void solve(vector<int>&arr , int n , int indx , int sum , vector<int>&path){
        
        if (indx==n){
            ans.push_back(sum);
            return;
        }
        
        path.push_back(arr[indx]);
        sum+=arr[indx];
        solve(arr,n,indx+1,sum,path);
        path.pop_back();
        sum-=arr[indx];
        solve(arr,n,indx+1,sum,path);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int>path;
    
        solve(arr,N,0,0,path);
        
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends