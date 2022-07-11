int mctFromLeafValues(vector<int>& arr) {
        stack<int> stack;
        int n = arr.size();
        int res = 0;
        for(int i=0; i<n; i++)
        {
            int num = arr[i];
            while(!stack.empty() and stack.top()<=num)
            {
                int curr = stack.top();
                stack.pop();
                if(!stack.empty())
                    res = res + curr*min(stack.top(), num);
                else
                    res = res + curr*num;
            }
            stack.push(num);
        }
        while(stack.size()>=2)
        {
            int val = stack.top();
            stack.pop();
            res = res + stack.top()*val;
        }
        return res;
    }
