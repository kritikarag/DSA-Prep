//https://leetcode.com/problems/minimize-manhattan-distances/description/

int minimumDistance(vector<vector<int>>& points) {
      int n = points.size();
      
      multiset<int>sum,diff;
      
      for(int i=0;i<n;i++){
          sum.insert(points[i][0]+points[i][1]);
          diff.insert(points[i][0]-points[i][1]); 
      }        
      int ans = INT_MAX;
      
      for(int i=0;i<n;i++){
          int s = points[i][0]+points[i][1];
          int d = points[i][0]-points[i][1];

          sum.erase(sum.lower_bound(s));
          diff.erase(diff.lower_bound(d));

          ans = min(ans,max((*sum.rbegin()-*sum.begin()),(*diff.rbegin()-*diff.begin())));

          sum.insert(s);
          diff.insert(d);
      }
      
      return ans;
  }
