class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> fctr;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                fctr.insert(i);
                fctr.insert(n/i);
            }
        }
        if(k>fctr.size())
            return -1;
        else
        {
            int itr=0;
            for(auto x:fctr)
            {
                if(itr+1==k)
                    return x;
                itr++;
            } 
        }
        return 0;
    }
};