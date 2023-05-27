// https://leetcode.com/problems/lru-cache/description/

#include<bits/stdc++.h>
using namespace std;
class LRUCache{
    public:
    class  Node
    {
    public:
        int key, value;
        Node *prev;
        Node *next;

        Node(int _key, int _value)
        {
            key = _key;
            value = _value;
            prev = NULL;
            next = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int _key){
        if(mp.find(_key)!=mp.end()){
            Node *temp = mp[_key];
            int res = temp->value;
            mp.erase(_key);
            deletenode(temp);
            addnode(temp);
            mp[_key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int _key, int value){
        if(mp.find(_key)!=mp.end()){
            Node *existingnode = mp[_key];
            mp.erase(_key);
            deletenode(existingnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(_key,value));
        mp[_key] = head->next;
    }
};
