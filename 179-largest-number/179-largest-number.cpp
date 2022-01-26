class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin() , nums.end() ,[](int &a , int &b){
            string p = to_string(a);
            string q = to_string(b);
            return p+q>q+p;
        });
        
        string res = "";
        for(auto it: nums){
            res+= to_string(it);
        }
        if(nums[0]==0)return "0";
        return res;
    }
};