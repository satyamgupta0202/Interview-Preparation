class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cntx=0,cnty=0,x=0,y=0;
        int n = nums.size();
        for(auto it: nums)
        {
            if(it==x)
            {
                cntx++;
            }
            else if(it==y)
            {
                cnty++;
            }
            else if(cntx==0)
            {
                cntx=1;
                x=it;
            }
            else if(cnty==0)
            {
                cnty=1;
                y=it;
            }
            else
            {
                cntx--;
                cnty--;
            }
        }
        
        cntx=0;
        cnty=0;
        for(auto it: nums)
        {
            if(it==x)
            {
                cntx++;
            }
           else if(it==y)
            {
                cnty++;
            }
        }
        vector<int>ans;
        if(cntx> n/3)
        {
            ans.push_back(x);
        }
        if(cnty> n/3)
        {
            ans.push_back(y);
        }
            
        return ans;
        
    }
};


/**
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        
        for(auto it: nums){
            mp[it]++;
        }
        vector<int>ans;
        for(auto it: mp){
            if(it.second > floor(n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

**/
