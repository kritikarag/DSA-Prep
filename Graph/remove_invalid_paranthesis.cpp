// https://leetcode.com/problems/remove-invalid-parentheses/description/

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
set<string> vis; 
vector<string> removeInvalidParentheses(string s)
{
    string temp = ""; 
    int n = s.length();

    queue<string> q;
    q.push(s);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            string curr = q.front();
            q.pop();
            if(vis.find(curr)!=vis.end())continue;
            vis.insert(curr);
            //cout<<curr<<" ";

            int flag = true;

            int open = 0, close = 0;
            int len = curr.length();
            for (int i = 0; i < len; i++)
            {
                if (curr[i] == '(')
                    open++;
                if (curr[i] == ')')
                    close++;

                if (close > open)
                {
                    flag = false;
                    break;
                }
                if (i == len - 1 && open != close)
                {
                    flag = false;
                }
            }
            if (flag)
                ans.push_back(curr);

            if (len == 1)
            {
                q.push("");
                continue;
            }

            for (int i = 0; i < len; i++)
            {
                if (curr[i] != '(' && curr[i] != ')')
                    continue;
                string child;
                
                if (i == 0)
                {
                    child = curr.substr(i + 1);
                }
                else if (i == len - 1)
                {
                    child = curr.substr(0, i);
                }
                else
                {
                    child = curr.substr(0, i) + curr.substr(i + 1);
                }
                //cout << "Parent: " << i<< " " <<curr << " Child: " << child << endl;
                q.push(child);
            }
        }
        if (ans.size())
            break;
    } 
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> v=removeInvalidParentheses(s);
    for(string i:v){
        cout<<i<<" ";
    }
    return 0;
}
