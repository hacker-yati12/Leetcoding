class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        int n=s.size();
        st.push("(");
        s.push_back(')');
        int res=0;
        for(int i=0;i<=n;)
        {
            if(s[i]==' ')
            {
                i++;
            }
            else if(s[i]=='(')
            {
                st.push("(");
                i++;
            }
            else if(s[i]>='0' and s[i]<='9')
            {
                string str="";
                while(s[i]>='0' and s[i]<='9')
                {
                    str+=s[i];
                    i++;
                }                
                st.push(str);
            }
            else if(s[i]=='-' and s[i+1]=='(')
            {
                st.push("-");
                i++;
            }
            else if(s[i]=='-')
            {
                string str="-";
                i++;
                while(s[i]>='0' and s[i]<='9')
                {
                    str+=s[i];
                    i++;
                }
                
                st.push(str);
            }
            else if(s[i]==')')
            {
                int val=0;
                while(st.top()!="(")
                {
                    val+=stoi(st.top());
                    st.pop();
                }
                st.pop();
                if(!st.empty() and st.top()=="-")
                {
                    val=val*-1;
                    st.pop();
                }
                st.push(to_string(val));
                i++;
            }
            else
                i++;  
        }
        return stoi(st.top());
    }
};