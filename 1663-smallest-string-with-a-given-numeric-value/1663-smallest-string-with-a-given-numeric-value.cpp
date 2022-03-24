class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string s = "";
        int sum=0;
        
        for(int i=1;i<=n;i++)
        {
            s.push_back('a');
            sum+=1;
        }
        int j = s.size()-1;
        while(sum!=k)
        {
            if(sum+25<=k)
            {
                s[j]='z';
                j--;
                sum=sum+25;
            }
            else
            {
                int p = k-sum;
                s[j]=s[j]+p;
                sum=k;
            }
        }
        return s;
    }
};