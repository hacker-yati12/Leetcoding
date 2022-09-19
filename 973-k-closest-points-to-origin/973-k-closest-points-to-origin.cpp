class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> vec;
        for(auto z:points)
        {           
            double x=z[0];
            double y=z[1];
            double dist=((x*x)+(y*y));
            pair<double,vector<int>> temp=make_pair(dist,z);
            vec.push_back(temp);
        }
        // for(auto x:vec)
        // {
        //     cout<<x.first<<endl;
        // }
        sort(vec.begin(),vec.end());
        vector<vector<int>> ans;
        while(k--)
        {
            ans.push_back(vec[k].second);
        }
        return ans;
    }
};