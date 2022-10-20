// https://leetcode.com/problems/largest-rectangle-in-histogram/

int largestRectangleArea(vector<int> &height)
{
    int n = height.size();
    stack<int> st;
    vector<int> left(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }
        if (!st.empty())
            left[i] = st.top() + 1;
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    vector<int> right(n, n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }
        if (!st.empty())
            right[i] = st.top() - 1;
        st.push(i);
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res, (right[i] - left[i] + 1) * height[i]);
    }

    return res;
}

int largestRectangleArea(vector<int> &height)
{
    height.push_back(0);
    int n = height.size();
    stack<int> st;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[st.top()] > height[i])
        {
            int h = height[st.top()];
            st.pop();
            int l = st.empty() ? -1 : st.top();
            res = max(res, h * (i - l - 1));
        }
        st.push(i);
    }
    return res;
}