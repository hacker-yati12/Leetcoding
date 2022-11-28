class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win,lose;
        for(int i=0;i<matches.size();i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        vector<int> vector1,vector2;
        for(auto x:win)
        {
            if(lose[x.first]!=0)
                continue;
            else
                vector1.push_back(x.first);
        }
        for(auto x:lose)
        {
            if(x.second==1)
                vector2.push_back(x.first);
        }
        vector<vector<int>> ans;
        ans.push_back(vector1);
        ans.push_back(vector2);
        return ans;
    }
};