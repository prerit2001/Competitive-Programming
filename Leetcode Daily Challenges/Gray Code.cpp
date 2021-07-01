class Solution {
public:
    vector<int> grayCode(int n) {
        int max_bit = n + 1;
        n = (1 << n);
        vector<int> a(n,0);
        vector<int> ans;
        ans.push_back(0);
        a[0] = 1;
        while(ans.size() < n){
            int prev = ans.back();
            for(int i = 0; i <= max_bit; i ++){
                int bit = (prev >> i) & 1;
                int new_num = bit == 0 ? prev + (1 << i) : prev - (1 << i);
                if(a[new_num] == 1) continue;
                else{
                    a[new_num] = 1;
                    ans.push_back(new_num);
                    break;
                }
            }
        }
        return ans;
    }
};