//Print from 1 to N

void print(int i, int n){
    if(i>n)return;
    cout<<i<<endl;
    print(i+1,n);
}

print(1,N);
//Print from N to 1

void print(int i, int n){
    if(i<1)return;
    cout<<i<<endl;
    print(i-1,n);
}

print(N,N);

//Print 1 to N Backtracking

void print(int i,int n){
    if(i<1)return;
    print(i-1,n);
    cout<<i<<endl;
}
print(N,N);

//Print N to 1 Backtracking

void print(int i, int n){
    if(i>N)return;
    print(i+1,n);
    cout<<i<<endl;
}
print(1,N);