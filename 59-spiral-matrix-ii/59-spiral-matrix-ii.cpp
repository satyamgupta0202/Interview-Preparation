class Solution {
public:
    
    void solve(vector<vector<int>>&ans , int row , int col , int i , int j , int &p)
    {
       // if(row==1 && col==1)
       // {
       //     ans[i][j]=p++;
       //     return;
       // }
        
       for(int k=j;k<=col;k++)
       {
           cout<<p<<endl;
           ans[i][k]=p++;
       }
    
        for(int k=i+1;k<=row;k++)
        {
            ans[k][col]=p++;
        }
        for(int k=col-1;k>=j;k--)
        {
            ans[row][k]=p++;
        }
        for(int k=row-1;k>i;k--)
        {
            ans[k][j]=p++;
        }
        
    }
    
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>>ans(n , vector<int>(n,0));
        int k = n;
        k = (k+1)/2;
        int p = 1;
        int r=n-1,c=n-1;
        int i=0,j=0;
        for(int z=1;z<=k;z++)
        {
           // cout<<i<<" "<<j<<" "<<r<<" "<<c<<endl;
            solve(ans ,r,c,i,j,p);
            i++;
            j++;
            r--;
            c--;
           // cout<<i<<" "<<j<<" "<<r<<" "<<c<<" "<<p<<endl;
        }
         return ans;
    }
};