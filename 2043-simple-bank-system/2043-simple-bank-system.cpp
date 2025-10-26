class Bank {
public:
    map<int, long long> mp;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        for(int i = 1; i <= balance.size(); i++)
            mp[i] = balance[i - 1];
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 <= n && account2 <= n && mp[account1] >= money) {
            mp[account1] -= money;
            mp[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account <= n) {
            mp[account] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account <= n && mp[account] >= money) {
            mp[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */