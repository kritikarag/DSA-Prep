bool subsetsum(int ind, int target, vector<int>&vec){
    if(target==0)return true;
    if(ind==0)return (vec[0]==target);

    bool not_take = subsetsum(ind-1,target,vec);
    bool take = false;
    if(vec[ind]<=target)take = subsetsum(ind-1,target-vec[ind],vec);

    return take||not_take;
}