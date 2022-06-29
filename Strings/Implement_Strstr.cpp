int strStr(string h, string ne) {
        int n=h.length();
        int m=ne.length();
        if(m==0)return 0;
        int i,j;
        for(i=0;i<n;i++){
            for(j=i;j<i+m;j++){
                if(h[j]!=ne[j-i])break;
            }
            if(j==(i+m))return i;
        } 
        return -1;
    }
