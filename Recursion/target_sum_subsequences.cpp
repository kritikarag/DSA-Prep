#include<bits/stdc++.h>
using namespace std;

//Printing all the subsequences
void targetsum(int ind,vector<int>&vec, vector<int>&res, int n,int sum, int target){
    
    // if(sum>target)return;
    if (ind >= n){
        if (sum == target)
        {
            for (auto it : res)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    //PICK CASE
    res.push_back(vec[ind]);
    targetsum(ind+1,vec,res,n,sum+vec[ind],target);
    //NOT PICK
    res.pop_back();
    targetsum(ind+1,vec,res,n,sum,target);
}

int main()
{
    vector<int> vec = {1, 2, 1};
    vector<int> res;
    int n = 3, target = 2,sum = 0;
    targetsum(0, vec, res, n, sum, target);

    return 0;
}

//Printing only one subsequence

bool targetsum(int ind, vector<int> &vec, vector<int> &res, int n, int sum, int target)
{
    // if(sum>target)return;
    if (ind >= n)
    {
        if (sum == target)
        {
            for (auto it : res)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    // PICK CASE
    res.push_back(vec[ind]);
    if(targetsum(ind + 1, vec, res, n, sum + vec[ind], target))return true;;
    // NOT PICK
    res.pop_back();
    if(targetsum(ind + 1, vec, res, n, sum, target))return true;
    
    return false;
}

int main()
{
    vector<int> vec = {1, 2, 1};
    vector<int> res;
    int n = 3, target = 2, sum = 0;
    targetsum(0, vec, res, n, sum, target);

    return 0;
}