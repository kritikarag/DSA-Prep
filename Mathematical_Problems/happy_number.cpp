bool isHappy(int n) {
        unordered_set<int> arr;

        while(n != 1 && arr.find(n) == arr.end()){
            arr.insert(n);
            int c = 0;
            while(n){
                c += (n%10) * (n%10);
                n /= 10;
            }
            n = c;
        }
        return n == 1;
    }
