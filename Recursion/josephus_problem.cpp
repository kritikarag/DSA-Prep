#include<bits/stdc++.h>
using namespace std;

void calculate(vector<int>&vec, int i, int k){
    if(vec.size()==1)return;
    int index = (i+k)%vec.size();
    vec.erase(vec.begin()+index);
    calculate(vec,index,k);
}
int main(){
    int n,k;
    cin>>n>>k;
    k--;
    vector<int>vec(n);
    iota(vec.begin(),vec.end(),1);
    calculate(vec,0,k);
    cout<<vec[0]<<endl;
    return 0;
}