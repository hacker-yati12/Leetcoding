class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tmp = 0, ans = 0, n = cardPoints.size();
        for(int i = 0; i < k; i++)
        {
            tmp += cardPoints[i];
        }
        ans = tmp;
        for(int i = 0; i < k; i++)
        {
            ans = max(ans, tmp +=cardPoints[n-i-1]-cardPoints[k-i-1]);
        }
        return ans;
    }
};