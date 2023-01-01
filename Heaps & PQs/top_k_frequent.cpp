vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (int x : nums) cnt[x] += 1;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(auto it:cnt){
        p.push({it.second,it.first});
        if(p.size()>k)p.pop();
    }
    vector<int>ans;
    while(k--){
        ans.push_back(p.top().second);
        p.pop();
    }
    
    return ans;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i : nums)
        mp[i]++;

    priority_queue<pair<int, int>> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}
