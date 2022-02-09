// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        // Your code here
        
        double ans = 0;
        double wt = 0;
        sort(arr,arr+n,[](Item a,Item b){
            return ((double) a.value/a.weight >= (double) b.value/b.weight);
        });
        
        
        for(int i=0;i<n;i++){
            
            if(wt+arr[i].weight <= W){
                wt+= arr[i].weight;
                
                ans+= (arr[i].value);
            }
            else{
                double k = W - wt;
                
                ans+= k* ((double)arr[i].value /(double) arr[i].weight);
                return ans;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends