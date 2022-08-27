//1st APPROACH
void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;
            else if(nums[i]==1)one++;
            else two++;
        }
        
        int j=0;
        while(zero--)nums[j++]=0;
        while(one--)nums[j++]=1;
        while(two--)nums[j++]=2;
    }

//2ND APPROACH

void sortColors(vector<int> &nums)
{
    int k = 0, j = nums.size() - 1, i = 0;
    for (int i = 0; i <= j; i++)
    {
        if (nums[i] == 0)
            swap(nums[i], nums[k++]);
        if (nums[i] == 2)
            swap(nums[i--], nums[j--]);
    }
}