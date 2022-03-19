class Solution {
public:
    
  bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

int check(int n){

    for(int i=n/2+1;i>1;i--){
        if(n%i == 0)return i;
    }
    return 1;
}

 
   
 
    int minSteps(int n) 
    {
    if(n==1)return 0;
    if(n==2)return 2;
     
    int dp[n+1];
    dp[0]=0;
    dp[1]=0;
    dp[2]=2;
    dp[3]=3;


    for(int i=4;i<=n;i++){
      
      if(isPrime(i)){
          dp[i]=i;
      }else{
          int k = check(i);
          dp[i] = dp[k]+(i/k);
      }
  }
        return dp[n];
    }
};