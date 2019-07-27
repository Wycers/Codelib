class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st, mn;
    MinStack() {
        while (!st.empty())
            st.pop();
        while (!mn.empty())
            mn.pop();
    }

    void push(int x) {
        if (mn.empty())
            mn.push(x);
        else
            mn.push(min(x, mn.top()));
        st.push(x);
    }

    void pop() {
        st.pop();
        mn.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
