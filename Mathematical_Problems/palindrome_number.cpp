bool palindrome(int n){
    int sum=0;
    while(n>sum){
        if(n<0 || (n!=0 && n%10==0))return false;
        sum = sum*10 + n%10;
        n/=10;
    }

    return (n==sum||n==sum/10);
}