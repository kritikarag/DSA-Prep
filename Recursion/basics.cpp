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

//REVERSE AN ARRAY

void reverse(int l, int r, int &arr[])
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverse(l + 1, r - 1, arr);
}

void reverse(int i, int n, int &arr[])
{
    if (i >= n / 2)
        return;

    swap(arr[i], arr[n - i - 1]);
    reverse(i + 1, n, arr);
}

// PALINDROME STRING

bool check(int i, int n, string &str){
    if(l>=n/2)return true;

    if(str[i]!=str[n-i-1])return false;

    check(i+1,n,str);
}