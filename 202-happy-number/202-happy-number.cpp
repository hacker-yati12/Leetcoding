class Solution {
public:
    int sum_of_squares(int num)
    {
        int sum=0;
        for(int i=num;i!=0;i/=10)
        {
            int dig=i%10;
            sum+=dig*dig;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=sum_of_squares(n);
        int fast=sum_of_squares(sum_of_squares(n));
        if(slow==1 || fast==1)
                return true;
        while(slow!=fast)
        {
            if(slow==1 || fast==1)
                return true;
            slow=sum_of_squares(slow);
            fast=sum_of_squares(sum_of_squares(fast));            
        }
        return false;
    }
};