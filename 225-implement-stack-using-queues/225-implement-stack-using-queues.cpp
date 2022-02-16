class MyStack {
public:
    deque<int>q;
    MyStack() {
        q.clear();
    }
    
    void push(int x) {
        q.push_front(x);
    }
    
    int pop() {
        int k =  q.front();
        q.pop_front();
        return k;
    }
    
    int top() {
        auto it = q.front();
        return it;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */