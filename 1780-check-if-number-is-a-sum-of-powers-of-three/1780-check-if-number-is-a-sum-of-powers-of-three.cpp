class Solution {
    bool check(int n, int i, int sum) {
        if(sum==n)
            return true;
        if(sum>n)
            return false;
        for(int k=i; pow(3,k)<=n; k++) {
            if(check(n, k+1, sum+pow(3,k)))
                return true;
        }
        return false;
    }
public:
    bool checkPowersOfThree(int n) {
        return check(n, 0, 0);
    }
};