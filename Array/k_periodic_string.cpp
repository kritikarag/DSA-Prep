string kPeriodic(string s, int k){
        // code here
    int n = s.size();
    sort(s.begin(), s.end());
    vector<int> m(26);
    for (int i = 0; i < n; i++) m[s[i] - 'a']++;
    
    int sz = 0, index = 0;
    string result = string(n, '#');
    while(result[index] == '#') {
        sz++;
        result[index] = '_';
        index = (index+k)%n; 
    }
    for(auto it: m) if(it % sz != 0) return "-1";
    result = string(n, '#');
    index = 0;
    int count = 0, val = 0;
    while(count != n) {
        while(result[index] != '#') index++;
        while(!m[val]) val++;
        while(result[index] == '#') {
            count++;
            result[index] = 'a' + val;
            index += k;
            index %= n;
        }
        m[val] -= sz;
    }
    return result;
    }