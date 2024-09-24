// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix
class Solution {
public:
    struct Node{
        Node* links[10];

        bool containsKey(char c){
            return links[c-'0']!=nullptr;
        }

        Node* getKey(char c){
            return links[c-'0'];
        }

        void put(char c, Node* node){
            links[c-'0'] = node;
        }
    };

    Node* root;
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        root = new Node();
        for(int k:arr1){
            Node* curr = root;
            string temp = to_string(k);

            for(int i=0;i<temp.length();i++){
                if(!curr->containsKey(temp[i])){
                    curr->put(temp[i], new Node());
                }

                curr = curr->getKey(temp[i]);
            }
        }

        int ans = 0;

        for(int k:arr2){
            Node* curr = root;
            string temp = to_string(k);
            int res = 0;

            for(int i=0;i<temp.length();i++){
                if(!curr->containsKey(temp[i])){
                    break;
                }
                res++;
                curr = curr->getKey(temp[i]);
            }

            ans = max(ans,res);
        }

        return ans;
    }
};
