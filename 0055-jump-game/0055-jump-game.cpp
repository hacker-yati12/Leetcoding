class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n= nums.size();
       queue<int> q;
       q.push(0);
       int far = 0;
       while(!q.empty()){
            int ind = q.front();
            q.pop();
            for(int i = ind+1;i<=min(ind+nums[ind], n-1);i++){
                if(i>far){
                    if(far==n-1) return true;
                    q.push(i);
                }
            }
            far = max(far, ind+nums[ind]);
       } 
       return far>=n-1;
    }
};