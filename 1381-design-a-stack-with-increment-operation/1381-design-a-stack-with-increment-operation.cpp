class CustomStack {
public:
    
    vector<int>v;
    int start = 0;
    int end = 0;
    int n;
    CustomStack(int maxSize) {
        
        v.resize(maxSize);
        start = 0 ;
        end = maxSize-1;
        n = maxSize;
        
    }
    
    void push(int x) {
        
       if(end>=0 && end<n)
       {
           v[end]=x;
           end--;
       }
        
    }
    
    int pop() {
        
        
        if(end+1<n)
        {
            end++;
            int k = v[end];
            return k;
        }
        else
        {
            return -1;
        }
        
    }
    
    void increment(int k, int val) {
        
        int j=n-1;
        
        for(int i=1;i<=k && j>end ;i++)
        {
            v[j]+=val;
            j--;
        }
        
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */