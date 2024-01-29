class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> st1;
    stack<int> st2;
    int n=0;
    // int n=0;
    void push(int x) {
        st1.push(x);
        n++;
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        // cout<<st2.top();
        n--;
        int ans=st2.top();

        st2.pop();
        return ans;
        // return st2.top();
    }
    
    int peek() {
        
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            
        }

        int ans=st2.top();

        // st2.pop();
        return ans;
    }
    
    bool empty() {
        return n==0;
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