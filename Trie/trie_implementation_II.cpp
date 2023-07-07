#include <bits/stdc++.h>

struct Node
{
    Node *links[26];
    int end = 0;
    int count_prefix = 0;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getKey(char ch)
    {
        return links[ch - 'a'];
    }

    void incprefix()
    {
        count_prefix++;
    }

    void setEnd()
    {
        end++;
    }

    void deleteEnd()
    {
        end--;
    }
    void delprefix()
    {
        count_prefix--;
    }
};
class Trie
{
    
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
        // Write your code here.
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->putKey(word[i], new Node());
            }

            node = node->getKey(word[i]);
            node->incprefix();
        }
        node->setEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->getKey(word[i]);
        }
        return node->end;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->getKey(word[i]);
        }

        return node->count_prefix;
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node = node->getKey(word[i]);
            node->delprefix();
        }
        node->deleteEnd();
        // Write your code here.
    }
};