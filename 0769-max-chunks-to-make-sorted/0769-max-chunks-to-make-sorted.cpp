class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0; i<n; i++) {
            if(empty(st) || arr[i]>st.top())
                st.push(arr[i]);
            else {
                int maxi = st.top();
                while(!empty(st) && arr[i]<st.top())
                    st.pop();
                st.push(maxi);
            }
        }
        return (int)st.size();
    }
};