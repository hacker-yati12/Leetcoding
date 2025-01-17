class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        for(int i=0; i<n-1; i++) {
            if(derived[i]==derived[i+1] && derived[i]==1) {
                derived[i]=0;
            } else if(derived[i]!=derived[i+1] && derived[i]==0)
                derived[i]=1;
        }

        if(derived[n-1]==0)
            return derived[0]==derived[n-1];
        else
            return derived[0]!=derived[n-1];
    }
};