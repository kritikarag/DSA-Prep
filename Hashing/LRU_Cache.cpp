#include<bits/stdc++.h>
using namepace std;
class LRUCache{
    class node{
        int key;
        int val;
        node *prev, *next;
        node(int _key,int _val){
            val = _val;
            key = _key;
            prev = NULL;
            next = NULL;
        }
    };

    node *head = {-1,-1};
    node *tail = {-1,-1};

    int cap;

    unordered_map<int,node*>mp;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }

    void addNode(node *newnode){
        node *temp = head->next;
        newnode -> next = temp;
        newnode -> prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node *delnode){
        node *delprev = delnode -> prev;
        node *delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev; 
        
    }

    int get(int key_){
        if(mp.find(key_)!=mp.end()){
            node *resnode = m[key_];
            int res = resnode -> val;
            mp.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            mp[key_]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value){
        if(mp.find(key_)!=mp.end()){
            node *temp = m[key_];
            mp.erase(key_);
            deleteNode(temp);
        }

        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        mp[key_] = head -> next;
    }
};
