#include<bits/stdc++.h>
using namespace std;
// Approach 1

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> res;
    unordered_set<string> st;
    for (string s : wordList)
    {
        st.insert(s);
    }
    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;

    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        if (vec.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
        }

        string word = vec.back();

        if (word == endWord)
        {
            if (res.size() == 0)
            {
                res.push_back(vec);
            }
            else if (res[0].size() == vec.size())
            {
                res.push_back(vec);
            }
        }

        for (int i = 0; i < word.length(); i++)
        {
            string temp = word;
            for (char c = 'a'; c <= 'z'; c++)
            {
                temp[i] = c;
                if (st.find(temp) != st.end())
                {
                    vec.push_back(temp);
                    q.push(vec);
                    usedOnLevel.push_back(temp);
                    vec.pop_back();
                }
                temp = word;
            }
        }
    }
    return res;
}

// Approach II

