class FenwickTree{
public:
	int n;
    vector<int> BIT;
	FenwickTree(int n){
		this->n = n + 1;
        BIT.resize(n+2);
		for(int i = 0; i <= n + 1; i ++){
			BIT[i] = 0;
		}
	}
	// initially all values of BIT are 0, so update all the delta's first
	void update(int idx, int value){
		while(idx <= n){
			BIT[idx] += value;
			idx += (idx & (-idx)); // eg: let idx = 13 and n = 16, then idx goes like -> 01101 (13) -> 01110 (14) -> 10000 (16)
		}
	}
	// compute sum from [1:l] 
	int pre_sum(int idx){
		int sum = 0;
		while(idx > 0){
			sum += BIT[idx];
			idx -= (idx & (-idx)); // eg: let idx = 13 and n = 16, then idx goes like -> 01101 (13) -> 01100 (12) -> 01000 (8) -> 00000 (0)
		}
		return sum;
	}
	// compute sum from [l:r]
	int range_sum(int l, int r){
		return pre_sum(r) - pre_sum(l - 1);
	}
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = 1e5+1;
        FenwickTree fenTree1(n),fenTree2(n);
        vector<int> left = rating, right = rating;
        int ans = 0;
        n = rating.size();
        for(int i = 0; i < n; i ++){
            int number_less_than_a_of_i = fenTree1.pre_sum(rating[i]);
            left[i] = number_less_than_a_of_i;
            fenTree1.update(rating[i],1);
        }
        for(int i = 0; i < n; i ++){
            // reverse
            int number_less_than_a_of_n_minus_i = fenTree2.pre_sum(rating[n-i-1]);
            right[n-i-1] = number_less_than_a_of_n_minus_i;
            fenTree2.update(rating[n-i-1],1);
            
        }
        
        for(int i = 0; i < n; i ++){
            ans += left[i] * ((n-i-1) - right[i]);
            ans += right[i] * ((i) - left[i]);
            
        }
        
        return ans;
        
    }
};