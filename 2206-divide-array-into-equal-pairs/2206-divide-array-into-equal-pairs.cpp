class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bitset<501>b;
        for(auto &x: nums) {
            b.flip(x);
        }
        return b.none();
    }
};