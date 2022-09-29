int sum(vector<int>&vec, int target){
    int n = vec.size();
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int right = n-1, left = 0;
            int target2 = target - vec[i] - vec[j];
            while(left<right){
                int curr_sum = vec[right]+vec[left];
                if(curr_sum<target)left++;
                else if(curr_sum>target)right--;
                else{
                    vector<int>curr;
                    curr.push_back(vec[i]);
                    curr.push_back(vec[j]);
                    curr.push_back(vec[right]);
                    curr.push_back(vec[left]);
                    res.push_back(curr);

                    //Removing duplicates of number 3
                    while(left<right-1 && vec[right]==vec[right-1])--right;

                    //Removing duplicates of number 4
                    while(left+1<right && vec[left]==vec[left+1])++left;
                }
            }

            //Removing duplicates of number 2
            while(j+1<n && vec[j+1]==vec[j])j++;
        }
        //Removing the duplicates of number 1
        while(i+1<n && vec[i]==vec[i+1])i++;
    }

    return res;
}