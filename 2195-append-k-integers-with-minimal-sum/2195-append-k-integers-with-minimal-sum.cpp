class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        long long ans = 0;
        
        sort(nums.begin() , nums.end());
        
        int cnt = 0;
        
        long long f = nums[0];
        
        if(f>1)
        {
            long long l = f - 1;
            
            if(l<=k)
            {
                cnt = l;
                ans = (l*(f))/2;
            }
            
            else
            {
                ans += ((long long)k * (long long)(1+k) )/(long long)2;
                cnt = k;
            }
        }
        
        if(cnt==k)return ans;
        
            bool ok = true;
            for(int i=0;i<n-1 && ok;i++)
            {
                if(nums[i] == nums[i+1]+1 || nums[i] == nums[i + 1]) continue;

                    long long j = nums[i+1]-nums[i]-1;
                    cout<<j<<endl;
                    if(cnt+j<k)
                    {     
                        ans+= (j*( (nums[i]+1)+(nums[i+1]-1)  ))/2;
                        cnt = cnt+j;
                    }

                    else
                    {
                        long long kp = nums[i]+1;
                        long long lol = k-cnt;
                        long long kd = nums[i]+lol;
                        ans+= (lol*(kp+kd))/2;
                        ok = false;
                        cnt = k;
                }   
            }
        
        if(ok)
        {
            long long pp = k-cnt;
            //cout<<"pp"<<pp<<endl;
            ans+=  pp*(nums[n-1]+1+ nums[n-1]+pp)/2;
        }
   
        
        return ans;

        
    }
};