class MedianFinder {
public:
    
    
   
   priority_queue<int>left;
   priority_queue<int , vector<int> , greater<int>> right;
   int cnt  = 0;
    
    
    MedianFinder() {
        cnt = 0;
    }
    
    void addNum(int num) {
        
        cnt++;
        if(cnt==1 || num<=left.top())
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }
        
        //size
        
        if(left.size()>right.size()+1)
        {
            auto k = left.top(); left.pop();
            right.push(k);
        }
        else if(right.size()>left.size()+1)
        {
            auto k = right.top(); right.pop();
            left.push(k);
        }
         
    }
    
    double findMedian() {
        
        if(cnt%2 == 0)
        {
            int n1 = left.top();
            int n2 = right.top();
            
            return long(n1+n2)/2.0;
        }
        else
        {
            if(left.size()>=right.size())
            {
                return double(left.top());
            }
            else
            {
                return double(right.top());
            }
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */