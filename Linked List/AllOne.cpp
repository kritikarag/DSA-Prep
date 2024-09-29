// https://leetcode.com/problems/all-oone-data-structure/description/
class AllOne {
public:
    struct Node{
        string val;
        Node *left, *right;

        Node(string v){
            val = v;
            left = nullptr;
            right = nullptr;
        }
    };
    unordered_map<string,int>mp1;
    unordered_map<string,Node*>mp2;

    Node* start ,*end;

    int mini = INT_MAX, maxi = INT_MIN;
    AllOne() {
        start = new Node(""); 
        end = new Node(""); 
        start->right = end; 
        end->left = start;
    }
    
    void inc(string key) {
        mp1[key]++;
        if(mp2.find(key)!=mp2.end()){
            Node* temp = mp2[key]->left;
            mp2[key]->right->left = temp;
            temp->right = mp2[key]->right;

            delete(mp2[key]);
            mp2.erase(key);

            while(temp->right!=end && mp1[temp->right->val]<mp1[key]){
                temp = temp->right;
            }

            Node* newnode = new Node(key);

            newnode->right = temp->right;
            newnode->left = temp;
            temp->right = newnode;
            newnode->right->left = newnode;

            mp2[key] = newnode; 
        }
        else{
            Node* newnode = new Node(key);
            newnode->right = start->right;
            newnode->left = start;
            start->right->left = newnode;
            start->right = newnode;
            
            mp2[key] = newnode; 
        }
    }
    
    void dec(string key) {
        mp1[key]--;
        if(mp1[key]==0){
            Node* temp = mp2[key];

            temp->right->left = temp->left;
            temp->left->right = temp->right;

            mp2.erase(key);
            mp1.erase(key);
            delete(temp);
        }
        else{
            Node* temp = mp2[key]->right;
            temp->left = mp2[key]->left;
            mp2[key]->left->right = temp;

            delete(mp2[key]);
            mp2.erase(key);

            while(temp->left!=start && mp1[temp->left->val]>mp1[key]){
                temp = temp->left;
            }

            Node* newnode = new Node(key);

            newnode->right = temp;
            newnode->left = temp->left;
            temp->left = newnode;
            newnode->left->right = newnode;

            mp2[key] = newnode;

        }
    }
    
    string getMaxKey() {
        if(end->left==start)return "";
        return end->left->val;
    }
    
    string getMinKey() {
        if(start->right==end)return "";
        return start->right->val;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
