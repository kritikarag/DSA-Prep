// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

bool check(vector<int>&arr, int k){
        int n = arr.size();

        //cout<<k<<endl;

        int start = 0, end = n-1;

        while(start<n-1 && arr[start+1]>=arr[start]){
            start++;
        }

        //if(start<n-1 && arr[start]<=arr[start+1])start++;

        while(end>start && arr[end]>=arr[start] && arr[end]>=arr[end-1]){
            end--;
        }
        if(arr[end]<arr[start])end++;

        int ans = max(0,end-start-1);
        //cout<<start<<" "<<end<<" "<<ans<<endl;

        if(ans<=k){
            return true;
        }

        end = min(end, n-2);

        while(end>=0 && arr[end]<=arr[end+1]){
            while(start>=0 && arr[start]>arr[end])start--;
            ans = min(ans, end-start-1);
            end--;
        }

        return ans<=k;

    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int ans = n-1, low = 0, high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(arr, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
