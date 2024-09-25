// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
class Solution {
public:
    struct Node{
        Node* links[26];
        int count = 0;

        bool containsKey(char c){
            return links[c-'a']!=nullptr;
        }

        void putKey(char c, Node* node){
            links[c-'a'] = node;
        }

        Node* getKey(char c){
            return links[c-'a'];
        }
    };

    Node* root;
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        root = new Node();

        for(string s:words){
            Node* curr = root;

            for(int i=0;i<s.length();i++){
                if(!curr->containsKey(s[i])){
                    curr->putKey(s[i], new Node());
                }
                curr = curr->getKey(s[i]);
                curr->count++;
            }
        }

        vector<int>ans(n,0);

        for(int k=0;k<n;k++){
            string s = words[k];
            int res = 0;
            Node* curr = root;

            for(int i=0;i<s.length();i++){ 
                curr = curr->getKey(s[i]);
                res+=curr->count; 
            }

            ans[k] = res; 
        }

        return ans;
    }
};
