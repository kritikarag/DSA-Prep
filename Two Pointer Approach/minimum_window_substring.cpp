// https://leetcode.com/problems/minimum-window-substring/description/

string minWindow(string s, string t) {
    int n = s.length(),count=0;

    int len = INT_MAX, low =0, start=0;

    unordered_map<char,int>mp,temp;
    for(char c:t){
        mp[c]++;
    } 

    for(int i=0;i<n;i++){
        if(mp[s[i]]>0)count++;
        mp[s[i]]--;

        if(count==t.length()){
            while(low<i && mp[s[low]]<0){
                mp[s[low]]++;
                low++;
            }
            if(len>i-low){
                len = i-low+1;
                start = low;
            }
            mp[s[low]]++;
            low++;
            count--;
        }
    }

    return len==INT_MAX?"":s.substr(start,len);
}
