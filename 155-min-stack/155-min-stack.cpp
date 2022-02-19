class MinStack {
public:
    
    stack<long>st;
    long ml = INT_MAX;
    
    
    MinStack() {
        
        ml = INT_MAX;
        // st.remove();
    }
    
    
    
    void push(int val) 
    {
        
        if(st.empty())
        {
            ml = val;
            st.push(val);
        }
        
        else 
        {
            if(val>=ml)
            {
                st.push(val);
            }
            else
            {
                st.push((long)2*val-ml);
                ml = val;
            }
        }
    }
    
    void pop() 
    {   
        if(st.empty())return;
        
        if(ml>st.top())
        {
            ml=2*ml - st.top();
            st.pop();
        }
        else if(st.top()>=ml)
        {
            st.pop();
        }
        
    }
    
    int top() {
        
        if(st.empty())return -1;
        int k ;
        if(ml>st.top())
        {
            //ml= 2*ml - st.top();
            k = ml;
        }
        else if(st.top()>=ml)
        {
            k = st.top();
        }
        
        return k;
    }
    
    int getMin() {
        if(st.empty())return -1;
        
        return ml;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */