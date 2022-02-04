// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long ans = 0;
    
    void merge(long long arr[] , long long l , long long m ,long long r){
        
        long long temp[r-l+1];
        
        long long i=l , j = m+1 , k=0;
        
        while(i<=m && j<=r){
            
            if(arr[i]<=arr[j]){
                
                temp[k++]=arr[i++];
                
            }else{
                
                ans+= m - i+1;
                temp[k++] = arr[j++];
            }
        }
        
        while(i<=m){
            temp[k++]=arr[i++];
        }
        while(j<=r){
           // ans+= m - i;
            temp[k++]=arr[j++];
        }
        
        for(int i=0;i<r-l+1;i++){
            arr[i+l] = temp[i];
        }
        
        
        
        
    }
    
    
    
    void mergeSort(long long arr[] , long long l , long long r){
        
        if(l>=r)return ;
        long long mid = l+ (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr,0,N-1); 
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends