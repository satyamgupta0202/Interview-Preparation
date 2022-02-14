// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
      int check(int nums[] , int target,int n){
        
        int possible=1;
        int temp=0;
        for(int i=0;i<n;i++){
            
            if(temp+nums[i]<=target){
                temp=temp+nums[i];
            }else{
                possible++;
                temp=nums[i];
            }
        }
        //cout<<possible<<endl;
        return possible; 
        
    }
    //Function to find minimum number of pages.
    int findPages(int nums[], int n, int m) 
    {
        //code here
       
        int end=0,start=0;
        for(int i=0;i<n;i++){
            end+=nums[i];
            start = max(start,nums[i]);
        }
        
        int mid=0;
        //calculated start,end
        while(start<=end){
            
            mid = start + (end-start)/2 ;
            
            int partition = check (nums,mid,n);
            //cout<<partition;
            
            if(partition > m ){
                start = mid+1;
            }else{
                end=mid-1;
            }

           
        }
      return end+1;  
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends