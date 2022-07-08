int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
        priority_queue<int>pq;
        for(int i=0;i<n-1;i++){
            if(h[i+1]>h[i]){
                int gap = h[i+1]-h[i];
                b-=gap;
                pq.push(gap);
                
                if(b<0){
                    if(l--){
                        b+=pq.top();
                        pq.pop();
                    }
                    else return i;
                }
            }
        }
        return n-1;
    }
