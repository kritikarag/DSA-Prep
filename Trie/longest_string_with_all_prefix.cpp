// https://www.codingninjas.com/studio/problems/complete-string_2687860

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }
};
Node *root;
bool checkPrefix(string word)
{
    Node *node = root;
    bool check = true;
    for (int i = 0; i < word.length(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            return false;
        }
        node = node->getNode(word[i]);
        if (!node->flag)
            return false;
    }
    return true;
}
string completeString(int n, vector<string> &a)
{
    // Write your code here.
    root = new Node();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        string word = a[i];
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->putKey(word[i], new Node());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (checkPrefix(a[i]))
        {
            if ((a[i].length() > ans.length()) || (a[i].length() == ans.length() && a[i] < ans))
            {
                ans = a[i];
            }
        }
    }

    if (ans == "")
        return "None";
    return ans;
}