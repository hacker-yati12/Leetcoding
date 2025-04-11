class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        int left, right;
        string s;
        for(int i = low; i <= high; i++) {
            left = 0;
            right = 0;
            s = to_string(i);
            if(s.size() & 1)
                continue;
            for(int j = 0; j < s.size(); j++) {
                if(j < s.size()/2)
                    left += s[j] - '0';
                else
                    right += s[j] - '0';
            }
            if(left == right)
                ans++;
        }
        return ans;
    }
};