class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int s1 = 0 ,s2 = 0;
        int n = gas.size();
        // for(int i=0;i<n;i++){
        //     gas.push_back(gas[i]);
        //     cost.push_back(cost[i]);
        // }
        for(int i=0;i<gas.size();i++)s1+=gas[i];
        for(int i=0;i<cost.size();i++)s2+=cost[i];
        
        if(s1<s2)return -1;
        
        int ans = 0;
        int sum = 0;
        
        for(int i=0;i<gas.size();i++){
            
            sum = sum + gas[i] - cost[i];
            
            if(sum < 0){
                ans=i+1;
                sum=0;
            }
            
        }
        
        return ans;
        
        
        
        
    }
};