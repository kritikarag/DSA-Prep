#include<bits/stdc++.h>
using namespace std;

pair<int,int> jobScheduling(vector<pair<int,pair<int,int>>>jobs){
    priority_queue<pair<int,pair<int,int>>>pq;
    int n=0;
    for(int i=0;i<jobs.size();i++){
        int profit = jobs[i].second.second;
        int id = jobs[i].first;
        int deadline = jobs[i].second.first;
        pq.push({profit,{deadline,id}});
        n=max(n,deadline);
    }

    //time Complexity -> N logN for storing element in the priority queue

    vector<int>res(n+1,-1);
    int count=0, totalprofit=0;
    for(int i=0;i<n;i++){
        auto temp = pq.front();
        int deadline = temp.second.first;
        for(int j=deadline;j>0;j--){
            if(res[i]==-1){
                res[i] = temp.second.second;
                count++;
                totalprofit+=temp.first;
                break;
            }
        }
    }
    //Time Complexity -> N*M where M is the max deadline

    return make_pair(count,totalprofit);
}