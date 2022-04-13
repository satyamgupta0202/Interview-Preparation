// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
#include<stdbool.h>


 // } Driver Code Ends
//User function Template for C

bool solve(int arr[] , int indx , int n)
{
    if(indx==n-1)return true;
    
    return (arr[indx]<=arr[indx+1] && solve(arr,indx+1,n));
}

bool arraySortedOrNot(int arr[], int n) 
{
     
    return solve(arr,0,n);
     
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        bool ans = arraySortedOrNot(arr, n);
        printf("%d\n", ans);

    }
    return 0;
}  // } Driver Code Ends