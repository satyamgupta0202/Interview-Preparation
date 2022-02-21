class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        deque<int>q;
        vector<int>ans;
        
        for(int i=0; i<n;i++)
        {
            while(!q.empty() && i-q.front()>=k)
            {
                q.pop_front();
            }
            
            while(!q.empty() && nums[q.back()]<=nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            
            if(i>=k-1)ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

/** Method1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        vector<int>ans;
        int n = nums.size();
        int i=0 , j=0;
        multiset<int , greater<int>>m;
        while(j<n)
        {
            while(j-i+1<k)
            {
                m.insert(nums[j]);
                j++;
            }
            
            if(j-i+1==k)
            {
                m.insert(nums[j]);
                
                auto temp = m.begin();
                ans.push_back(*temp);
                
                m.erase(m.find(nums[i]));
               
                i++;
                j++;
            }
        }
        return ans;
        
        
        
    }
};
**/