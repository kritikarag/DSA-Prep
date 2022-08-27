// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// METHOD-1 0.62s
vector<int> leaders(int a[], int n)
{
    // Code here
    stack<int> st;
    st.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= st.top())
            st.push(a[i]);
    }
    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

//METHOD-2   0.57s

vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> res;
    res.push_back(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= res.back())
            res.push_back(a[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}