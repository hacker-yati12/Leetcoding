class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi = -1;
        for(int i = 0; i <= num.size()-3; i++) {
            if(num[i] == num[i+1] && num[i] == num[i+2])
                maxi = max(maxi, num[i]-'0');
        }
        return (maxi == -1)?"": string(3, '0'+ maxi);
    }
};