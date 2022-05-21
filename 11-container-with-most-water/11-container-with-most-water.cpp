class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1;
        int res=0,ans=0;
        while(low<high)
        {
            if(height[low]<=height[high])
            {
                res=height[low]*(high-low);
                low++;
            }
            else
            {
                res=height[high]*(high-low);
                high--;
            }
            if(res>ans)
                ans=res;
        }
        return ans;
    }
};