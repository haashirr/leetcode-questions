class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    int peekElement = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekElement = x;
        }
        input.push(x);
    }
    
    int pop() { //amortized time complexity
        if(output.empty()) { //O(n)
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        //O(1)
         int val = output.top();
            output.pop();
            return val;
    }
    
    int peek() {
        if(output.empty()) {
            return peekElement;
        }
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */