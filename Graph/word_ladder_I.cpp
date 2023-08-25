// https://leetcode.com/problems/word-ladder/description/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string val;
    int level;

    Node(string _val, int _level) : val(_val), level(_level) {}
};

unordered_map<string, int> mp;
int ladderLength(string begin, string end, vector<string> &wordList)
{
    for (string s : wordList)
    {
        mp[s]++;
    }

    queue<Node *> q;
    Node *start = new Node(begin, 1);
    q.push(start);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        string word = curr->val;
        int level = curr->level;

        if (word == end)
            return level;
        for (int i = 0; i < word.length(); i++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (word[i] == c)
                    continue;

                string temp = word;
                temp[i] = c;

                if (mp[temp] > 0)
                {
                    mp.erase(temp);
                    Node *new_word = new Node(temp, level + 1);
                    q.push(new_word);
                }
            }
        }
    }

    return 0;
}