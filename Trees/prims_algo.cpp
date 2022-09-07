//PRIMS'S Algorithm is used to create minimum spanning tree

//BRUTE FORCE ALGORITHM
void primsAlgorithm(int v, vector<pair<int,int>>adj[]){
    vector<int>key(v,INT_MAX);
    vector<int>parent(v,-1);
    vector<bool>mstset(v,false);

    key[0]=0;

    for(int i=0;i<v-1;i++){
        int mini=INT_MAX,u;
        for(int j =0;j<v;j++){
            if(!mstset[i]&&key[j]<mini)
                mini = key[j],u=j;
        }

        mstset[u] = true;
        for (auto it : adj[u])
        {
            //it.first -> adjacent node
            //it.second -> weight of the edge connected to adjacent node
            if (!mstset[it] && key[it.first] > it.second)
            {
                parent[it.first] = u;
                key[it.first] = it.second;
            }
        }
    }
}

// Time Complexity will be greater than O(N^2)

//Priority Queue Implementation

void primsAlgorithm(int v, vector<pair<int, int>> adj[])
{
    vector<int> key(v, INT_MAX);
    vector<int> parent(v, -1);
    vector<bool> mstset(v, false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int,int>>pq;

    key[0] = 0;
    pq.push({0,0});
    for (int i = 0; i < v - 1; i++)
    {
        int u = pq.top().second;
        pq.pop();

        mstset[u] = true;
        for (auto it : adj[u])
        {
            // it.first -> adjacent node
            // it.second -> weight of the edge connected to adjacent node
            if (!mstset[it] && key[it.first] > it.second)
            {
                parent[it.first] = u;
                key[it.first] = it.second;
                pq.push({key[it.first], it.first});
            }
        }
    }
}

// Time Complexity will be O(nlogn)