//Chceck if ith bit of a number is set or not

bool setbit(int n, int k){
    int mask = 1 << k;
    return n&mask;
}

//Set ith bit of a number k should be 1

int setBit(int n, int k){
    int mask = 1 << k;
    return n|mask;
}

//Set ith bit of a number to 0

int setBit(int n, int k){
    int mask = ~(1<<k);
    return n&mask;
}

//Set last bit of a number to 0

int setBit(int n){
    return n&(n-1);
}

//Count the number of set bits

int numbits(int n){
    int count=0;
    while(n){
        if(n&1==1){
            count++;
            n>>1;
        }
    }
    return count;
}

int numbits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}