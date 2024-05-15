// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return links[bit]!=NULL;
    }

    Node* getNode(int bit){
        return links[bit];
    }

    void putKey(int bit, Node* node){
        links[bit] = node;
    }
};
class Solution {
public:
    using obj = pair<int,pair<int,int>>;
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        Node *root = new Node();
        sort(nums.begin(),nums.end());
        //priority_queue<obj,vector<obj>,greater<obj>>pq;
        vector<obj>pq;
        
        for(int i=0;i<q;i++){
            pq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(pq.begin(),pq.end());
        vector<int>ans(q,-1);
        int k = 0;
        for(int i=0;i<q;i++){
            int limit = pq[i].first;
            int number = pq[i].second.first;
            int index = pq[i].second.second;

            while(k<n && nums[k]<=limit){
                int curr_num = nums[k];
                Node* node = root;
                for(int j=31;j>=0;j--){
                    int bit = (curr_num>>j)&1;

                    if(!node->containsKey(bit)){
                        node->putKey(bit, new Node());
                    }
                    node = node->getNode(bit);
                }
                k++;
            }

            if(k==0)continue;

            int res = 0;
            Node* node = root;
            for(int j=31;j>=0;j--){
                int bit = (number>>j)&1;

                if(node->containsKey(1-bit)){
                    res = res|(1<<j);
                    node = node->getNode(1-bit);
                }
                else if (node->containsKey(bit)){
                    node = node->getNode(bit);
                }
                else break;
            }

            ans [index] = res;
        }

        return ans;
    }
};
