#include<bits/stdc++.h>
using namespace std;

void recursiveinsert(vector<int>&vec, int x){
    if (vec.size() == 0 || vec[vec.size() - 1] <= x)
    {
        vec.push_back(x);
        return;
    }
    int val = vec[vec.size()-1];
    vec.pop_back();
    recursiveinsert(vec,x);
    vec.push_back(val); 
}

void recursivesort(vector<int>&vec){
    if(vec.size()<=1)return;

    int temp = vec[vec.size()-1];
    vec.pop_back();

    recursivesort(vec);
    recursiveinsert(vec, temp);
}

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];

    recursivesort(vec);

    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    return 0;
}