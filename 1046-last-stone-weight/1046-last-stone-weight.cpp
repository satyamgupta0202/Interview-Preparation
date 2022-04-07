class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();
        priority_queue<int>q(stones.begin(),stones.end());
        
        while(q.size()>1){
            int one = q.top();
            q.pop();
            int two = q.top();
            q.pop();
            
            int f = abs(one-two);
            
            if(f){
                q.push(f);
            }
        }
        if(q.size()==0)return 0;
        return (q.top());
    }
};