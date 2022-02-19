#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ,k;
    cin>>n>>k;
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    ///begin now!!!
    priority_queue<int  , vector<int> , greater<int>>pq;
    
    for(int i=0;i<n;i++){
        pq.push(a[i]);
        if(pq.size()>k)
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }
    
    while(!pq.empty())
    {
         cout<<pq.top()<<" ";
            pq.pop();
    }
    cout<<'\n';
    
}




int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
	    solve();
	}
	return 0;
}