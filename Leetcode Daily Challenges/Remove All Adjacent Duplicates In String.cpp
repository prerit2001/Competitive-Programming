// stack
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(int i = 0; i < s.size();){
            int idx = i;
            if(i < s.size() - 1 and s[i] == s[i+1]){
                s.erase(i,2);
                if(!st.empty()){
                    i = st.top();
                    st.pop();
                }
            }
            else{
                st.push(i);
                i ++;
            }
        }
        return s;
    }
};