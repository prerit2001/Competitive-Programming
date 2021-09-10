class Solution{
public:
    int maxLength(string S){
        stack<int> s;
        stack<int> x;
        for(int i = 0; i < S.size(); i ++){
            if(S[i] == '('){
                s.push(i);
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
                else{
                    x.push(i);
                }
            }
        }
        int last = S.size();
        int ans = 0;
        while(x.size() > 0 and s.size() > 0){
            if(x.top() > s.top()){
                ans = max(ans,last - x.top() - 1);
                last = x.top();
                x.pop();
            }
            else{
                ans = max(ans,last - s.top() - 1);
                last = s.top();
                s.pop();
            }
        }
        while(x.size() > 0){
            ans = max(ans,last - x.top() - 1);
            last = x.top();
            x.pop();
        }
        while(s.size() > 0){
            ans = max(ans,last - s.top() - 1);
            last = s.top();
            s.pop();
        }
        ans = max(ans, last);
        return ans;
    }
};