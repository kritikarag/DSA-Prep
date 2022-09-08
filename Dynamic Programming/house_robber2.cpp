#include<bits/stdc++.h>
using namespace std;

int maxAmount(int ind, int end, vector<int>&vec){
    int prev2 = vec[ind];
    int prev1 = max(prev2,vec[ind+1]);

    for(int i=ind+2;i<end;i++){
        int curr = max(prev1,prev2+vec[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> vec = {2, 1, 4, 9, 11, 13, 12};
    int n = vec.size();
    int start = maxAmount(0,n-1,vec);
    int finish = maxAmount(1,n,vec);
    cout << max(start,finish) << endl;

    return 0;
}