class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s)
        {
            switch(x)
            {
                case '(':
                case '{':
                case '[':
                    st.push(x);
                    break;
                case ')':
                    {
                        if(!st.empty() && st.top()=='(')
                        {
                            st.pop();
                            break;
                        }
                        else
                            return false;
                    }
               case '}':
                    {
                        if(!st.empty() && st.top()=='{')
                        {
                            st.pop();
                            break;
                        }
                        else
                            return false;
                    }
                case ']':
                    {
                        if(!st.empty() && st.top()=='[')
                        {
                            st.pop();
                            break;
                        }
                        else
                            return false;
                    }    
            }
        }
        return st.empty();
    }
};