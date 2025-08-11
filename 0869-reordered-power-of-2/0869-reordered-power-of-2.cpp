class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        do {
            int n1 = stoi(s);
            if(log2(n1) == (int)log2(n1*1.0))
                return true;
        } while(next_permutation(s.begin(), s.end()));
        return false;
    }
};