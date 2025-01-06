class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        if(n == 1) 
            return {0};
        int lb=0, lc=0, rb=0, rc=0;
        for(int i=1; i<n ;i++) {
            if(boxes[i]=='1') {
                rb++;
                rc += i;
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(lc+rc);
            if(boxes[i]=='1') {
                lb++;
                lc += lb;
            } else {
                lc+=lb;
            }
            if(i<n-1) {
                if(boxes[i+1]=='1') {
                    rc -= rb;
                    rb--;
                } else {
                    rc -= rb;
                }
            }
        }
        return ans;
    }
};