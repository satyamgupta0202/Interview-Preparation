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