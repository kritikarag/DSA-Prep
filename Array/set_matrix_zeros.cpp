void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)v.push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<v.size();i++)
        {
            int x = v[i].first;
            int y = v[i].second; 
            for(int k=0;k<matrix[0].size();k++)
            {
                matrix[x][k] = 0;
            }
            for(int k=0;k<matrix.size();k++)
            {
                matrix[k][y] = 0;
            }
        }
    }
