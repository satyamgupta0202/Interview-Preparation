// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

   int check(vector<int>v , int num , int n)
   {
      int low = 0 , high = n-1;
       
       while(low<=high)
       {
           int mid = low +  (high-low)/2;
           
           if(v[mid]>num)
           {
               high =  mid-1;
           }else{
               low=mid+1;
           }
       }
       return low;
   }


    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int k = (row*col)/2;
        
        int low = 0;
        int high = 1e9;
        
        while(low<=high)
        {
            int mid =  (high+low)>>1;
            
            int c =  0 ;
            
            for(int i=0;i<row;i++){
                c+=check(matrix[i] , mid , col);
            }
            
            if(c<=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends