// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

int solve(int index, vector<string>&words, vector<int>&score, map<char,int>mp){
    if(index>=words.size())return 0;
    //if(dp[index]!=-1)return dp[index];

    int not_take = solve(index+1, words, score, mp);

    int take=0,flag =1,curr=0;

    string word = words[index];

    for(int i=0;i<word.length();i++){
        if(mp[word[i]]<=0){
            flag = 0;
            break;
        }
        curr+=score[word[i]-'a'];
        mp[word[i]]--;
    }

    if(flag){
        take = curr+solve(index+1,words,score,mp);
    }

    return max(take,not_take);
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    map<char,int>mp;
    for(char &c:letters){
        mp[c]++;
    }

    return solve(0,words,score,mp);
}
