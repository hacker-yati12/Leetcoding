class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> idx;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(mp[index] != 0) {
            idx[mp[index]].erase(index);
        }
        mp[index] = number;
        idx[number].insert(index);
    }
    
    int find(int number) {
        if(idx[number].size() == 0)
            return -1;
        else 
            return (*idx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */