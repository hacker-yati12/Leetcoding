class Solution {
private:
    bool check(int num) {
        vector<int> v(10);
        while(num > 0) {
            v[num % 10]++;
            num /= 10;
        }
        for(int i = 0; i <= 9; i++) {
            if(v[i] > 0 && v[i] != i)
                return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i <= 1224444; i++) {
            if(check(i))
                return i;
        }
        return -1;
    }
};