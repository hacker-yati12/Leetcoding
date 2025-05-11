class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int prev = -1;
        for(int i=0; i<arr.size(); i++) {
            if(!(arr[i]&1)) {
                prev = i;
                continue;
            }
            if(i-prev>=3)
                return true;
        }
        return false;
    }
};