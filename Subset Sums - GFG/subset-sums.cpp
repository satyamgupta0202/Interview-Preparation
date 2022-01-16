// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    void solve(vector<int>arr , int indx , int n , vector<int>&ans,vector<int>&path) {
        
        if(indx==n){
            int sum=0;
            for(int i=0;i<path.size();i++){
                sum+=path[i];
            }
            ans.push_back(sum);
            return ;
        }
        
        if(indx>=n)return ;
        
        path.push_back(arr[indx]);
        solve(arr,indx+1,n,ans,path);
        path.pop_back();
        solve(arr,indx+1,n,ans,path);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        //ans.push_back(0);
        int n = arr.size();
        vector<int>path;
        solve(arr,0,n,ans,path);
        sort(ans.begin(),ans.end());
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