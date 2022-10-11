// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Dijksta's Algorithm : Shortest distance for undirected weighted graph with positive edge weights

Using Queue:-
TC: ElogV
vector<int>dijkstra(int v, vector<pair<int,int>>adj[], int src){
    vector<int>dis(v+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int curr = it[1];
            int temp = it[0];

            if(dis[temp]>weight+curr){
                dis[temp] = weight+curr;
                pq.push({dis[temp],temp}); 
            }
        }
    }
    return dis;
}

Using Set : -

vector<int>dijkstra(int v, vector<pair<int, int>> adj[], int src)
{
    vector<int> dis(v + 1, INT_MAX);
    set<pair<int,int>>st;
    st.insert({0,src});
    dis[src]=0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int weight = it.first;
        st.erase(it);

        for(auto it: adj[node]){
            int temp = it[0];
            int curr = it[1];

            if(dis[temp]>curr+weight){
                if(dis[temp]!=INT_MAX){
                    st.erase({dis[temp],temp});
                }

                dis[temp] = weight + curr;
                st.insert({dis[temp],temp});
            }
        }
    }
    return dis;
}