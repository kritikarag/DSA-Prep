// https://leetcode.com/problems/min-stack/description/

class MinStack
{
public:
    stack<int> st;
    int mini = INT_MAX;
    MinStack()
    {
    }

    void push(int val)
    {
        if (val <= mini)
        {
            st.push(mini);
            mini = val;
        }
        st.push(val);
    }

    void pop()
    {
        if (mini == st.top())
        {
            st.pop();
            mini = st.top();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
};