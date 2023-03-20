// https://leetcode.com/problems/can-place-flowers/description/

bool canPlaceFlowers(vector<int>& fb, int n) {
    if (n == 0) {
        return true;
    }
    int count = 0;
    for (int i = 0; i < fb.size(); i++) {
        if (fb[i] == 0 && (i == 0 || fb[i-1] == 0) && (i == fb.size()-1 || fb[i+1] == 0)) {
            fb[i] = 1;
            count++;
            if (n == count) {
                return true;
            }
        }
    }
    return false;
}