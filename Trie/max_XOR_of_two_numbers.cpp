// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/1181033444/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return links[bit] != nullptr;
    }

    Node *getNode(int bit)
    {
        return links[bit];
    }

    void putKey(int bit, Node *node)
    {
        links[bit] = node;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Node *root = new Node();

        for (int i = 0; i < nums.size(); i++)
        {
            Node *node = root;
            int number = nums[i];
            for (int i = 31; i >= 0; i--)
            {
                int bit = (number >> i) & 1;

                if (!node->containsKey(bit))
                {
                    node->putKey(bit, new Node());
                }
                node = node->getNode(bit);
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int number = nums[i];
            int curr = 0;
            Node *node = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (number >> i) & 1;
                if (node->containsKey(1 - bit))
                {
                    curr = curr | (1 << i);
                    node = node->getNode(1 - bit);
                }
                else
                    node = node->getNode(bit);
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};