// Hill Trough
class Solution {
public:
    int candy(vector<int>& a) {
        int ans = 0;
        bool flag = 0;
        int prev_last = 0;
        int n = a.size();
        for(int i = 0; i < n; i ++){
            int last = a[i];
            int first = i;
            i ++;
            while(i < n and a[i] < last){
                last = a[i];
                i ++;
            }
            i--;
            last = i;
            map<int,int> mp;
            for(int i = last; i >= first; i --){
                mp[a[i]]++;
            }
            if(flag == 0){
                int cnt = 1;
                for(auto it : mp){
                    ans += cnt * it.second;
                    cnt ++;
                }
                flag = 1;
                prev_last = 1;
            }
            else{
                int exe = 0, ex = 0;
                int cnt = 1;
                for(auto it : mp){
                    ans += cnt * it.second;
                    exe = cnt;
                    ex = it.first;
                    cnt ++;
                }
                
                if(ex != a[first - 1] and exe <= prev_last) ans += prev_last + 1 - exe;  
                if(first == last){
                    if(ex != a[first - 1] and exe <= prev_last){
                        prev_last += 1;
                    }
                    else{
                        prev_last = exe;
                    }
                }
                else{
                    prev_last = 1;
                }
            }
        }
        return ans;
    }
};