class StockSpanner {
public:
    
    stack<pair<int,int>>st;
    
    int i=0;
    
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        i++;
        
        while(!st.empty() && st.top().first <= price)
        {
            cout<<price<<endl;
            st.pop();
        }
        
        if(!st.empty() && st.top().first> price)
        {
            int k = st.top().second;
            st.push({price,i});
            return i-k;
        }
        
        st.push({price,i});
     //   cout<<i<<endl;
        return i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */