// https://practice.geeksforgeeks.org/problems/complement3911/1

/*Let's say we chose indices L and R 

Now let's look at what is the net change in number of 1s in string S when we complement the characters between L and R.
Let's say initially it has A 0s and B 1s. Eventually, there will be B 0s and A 1s.
So, number of 1s increase by A - B.We want to choose a subarray which maximises this.
Now if we change 1s to -1 and 0s to 1, then the sum of values will give us A - B.
Then, we have to find a subarray with maximum sum, which can be done via Kadane’s Algorithm.*/

vector<int> findRange(string str, int n) {
    // code here
    int curr =0, maxi =0,l=0,r=0,start=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0')curr++;
        else curr--;
        if(curr<0){
            curr = 0;
            start = i+1;
        }
        if(maxi<curr){
            maxi = curr;
            l = start+1;
            r = i+1;
        }
    }
    if(maxi==0)return {-1};
    return {l,r};
}