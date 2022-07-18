#include<bits/stdc++.h>
using namespace std;

string convert(int n){
    string res;
    while(n>0){
        n-=1;
        res = char(n%26+'A')+res;
        n/=26;
    }
    return res;
}