int dis(vector<int>&v1, vector<int>&v2){
        return ((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[1]-v2[1])*(v1[1]-v2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int>s({dis(p1,p2),dis(p2,p3),dis(p3,p4),dis(p1,p3),dis(p1,p4),dis(p2,p4)});
            return !s.count(0)&& s.size()==2;
        }
