class MinStack {
public:
    stack<int> st;
    stack<int> minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minstack.empty())
        {
            minstack.push(val);
        }
        else
        {
            minstack.push(min(minstack.top(),val));
        }
        st.push(val);
    }
    
    void pop() {
        st.pop();
        minstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
