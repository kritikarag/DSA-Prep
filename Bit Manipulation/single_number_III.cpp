// https://leetcode.com/problems/single-number-iii/

vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();

    int res = 0;
    for(int i:nums){
        res^=i;
    }

    vector<int>v1,v2;

    int count = 0;

    while(res){
        if(res&1)break;
        res>>=1;
        count++;
    }

    int temp = 1<<count;
    int n1=0,n2=0;
    for(int i:nums){
        if(i&temp){
            n1^=i;
        }
        else{
            n2^=i;
        }
    } 

    return {n1,n2};
}
