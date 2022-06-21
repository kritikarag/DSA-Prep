int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int tc=0,cc=0,s=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            tc+=gas[i]-cost[i];
            cc+=gas[i]-cost[i];
            if(cc<0){
                cc=0;
                s=i+1;
            }
        }
        return (tc>=0)?s:-1;
    }
