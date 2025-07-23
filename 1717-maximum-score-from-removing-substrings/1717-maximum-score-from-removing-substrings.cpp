class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ctx = 0, cty = 0;
        if(x < y) {
            for(auto x: s) {
                if(st.empty()) 
                    st.push(x);
                else if(x == 'a' && st.top()=='b') {
                    st.pop();
                    cty++;
                } else {
                    st.push(x);
                }
            }

            int b = 0;
            while(!st.empty()) {
                if(st.top()=='b') 
                    b++;
                else if(st.top()=='a' && b>0) {
                    b--;
                    ctx++;
                } else 
                    b = 0;

                st.pop();
            }
        } else {
            for(auto x: s) {
                if(st.empty()) 
                    st.push(x);
                else if(x == 'b' && st.top()=='a') {
                    st.pop();
                    ctx++;
                } else {
                    st.push(x);
                }
            }

            int a = 0;
            while(!st.empty()) {
                if(st.top()=='a') 
                    a++;
                else if(st.top()=='b' && a>0) {
                    a--;
                    cty++;
                } else 
                    a = 0;

                st.pop();
            }
        }
        return x*ctx + y*cty;
    }
};