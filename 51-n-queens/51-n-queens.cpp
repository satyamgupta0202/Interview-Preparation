class Solution {
public:
    bool check(vector<string>&mat , int row , int col ,int n){

   //upper left
   int i=row , j=col;
   while(i>=0 && j>=0){
       if(mat[i][j]=='Q')return false;
       i--;
       j--;
   }

   i=row , j=col;
   while( j>=0){
       if(mat[i][j]=='Q')return false;
       j--;
   }

   i=row , j=col;
   while(i<n && j>=0){
       if(mat[i][j]=='Q')return false;
       i++;
       j--;
   }
 return true;

}



void solve(vector<string>&mat,int n , vector<vector<string>>&ans , int col){

    if(col == n) {
        ans.push_back(mat);
        return;
    }

    for(int row = 0;row<n;row++){

        if(check(mat,row,col,n)){
            mat[row][col] = 'Q';
            solve(mat,n,ans,col+1);
            mat[row][col]='.' ;
        }
    }


}
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>ans;
    vector<string>mat(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
         mat[i]=s;
    }
    solve(mat,n,ans,0);
    return ans;
    }
};