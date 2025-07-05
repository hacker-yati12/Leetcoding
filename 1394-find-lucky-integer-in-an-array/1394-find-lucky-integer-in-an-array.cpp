class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for(auto &x: arr) {
            mp[x]++;
        }
        auto itr = mp.rbegin();
        while(itr != mp.rend()) {
            if(itr->first == itr->second)
                return itr->first;
            itr++;
        } 
        return -1;
    }
};