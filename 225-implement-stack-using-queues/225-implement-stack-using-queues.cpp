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
class Stack {
public:
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		que.pop();
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};
**/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */