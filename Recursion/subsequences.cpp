// Contigious/Non-contiguos subsequence which follows the order
#include<bits/stdc++.h>
using namespace std;
void subsequence(int ind,vector<int>&vec, vector<int>&res, int n){
    if(ind>=n){
        for(auto it: res){
            cout<<it<<" ";
        }
        if(res.size()==0)cout<<"{}";
        cout<<endl;
        return;
    }
    //Choose the current index element
    res.push_back(vec[ind]);
    subsequence(ind+1,vec,res,n);
    
    //Not choose the current index element
    res.pop_back();
    subsequence(ind+1,vec,res,n);// This statement can be inserted above line 14 to recursively call not pick
    // function 
}

int main(){
    vector<int>vec = {3,1,2};
    vector<int>res;
    int n = 3;
    subsequence(0, vec, res, n);

    return 0;
}
