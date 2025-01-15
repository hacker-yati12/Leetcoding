class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ct = __builtin_popcount(num2);
        bitset<32> bt;
        int tt = 1;
        for(int i=0; i<32; i++) {
            if(tt & num1)
                bt.set(i);
            tt = tt<<1;
        }
        int ans = 0;
        for(int i = 31; i>=0; i--) {
            if(bt.test(i)) {
                ans += (1<<i);
                ct--;
                if(ct == 0)
                    break;
            }
        }
        if(ct>0) {
            for(int i=0; i<32; i++) {
                if(!bt.test(i)) {
                    ans += (1<<i);
                    ct--;
                }
                if(ct == 0)
                    break;
            }
        }
        return ans;
    }
};