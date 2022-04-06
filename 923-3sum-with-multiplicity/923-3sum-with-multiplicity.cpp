class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        long ans = 0;
        long key , freq;
        //map to store frequency of elements
        map<int,int> m;
        for(int i : a) m[i]++;
        for(auto i = m.begin() ; i!= m.end() ; i++)
        {
            key = i->first;
            freq = i->second;
            //Triplet with 3 identical numbers then add nC3 , n is frequency 
            if(freq>=3 and 3*key == target) ans += freq*(freq-1)*(freq-2)/6;
            //Triplet with 2 identical numbers 
            if(freq>=2 and m.find(target-2*key) != m.end() and m.find(target-2*key) != i ) 
                ans += m[target-2*key] * freq * (freq-1) / 2;
            //Triplet with disctinct elements
            if(i == prev(m.end(),2)) continue;
            auto j = i , k = m.end();
            j++;
            k--;
            while( j!=k and  k != prev(j,1) )
            {
                int sum = key + j->first + k->first;
                if(sum == target)
                {
                    ans += m[key]*m[j->first]*m[k->first];
                    j++;
                    k--;
                }
                else if(sum < target) j++;
                else k--;
            }
        }
        return ans % 1000000007;
    }
};