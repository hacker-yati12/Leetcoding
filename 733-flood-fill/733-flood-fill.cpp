class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int curr)
    {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=curr)
            return;
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,curr);
        dfs(image,sr,sc-1,color,curr);
        dfs(image,sr,sc+1,color,curr);
        dfs(image,sr+1,sc,color,curr);
    }
    public:    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])
            return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};