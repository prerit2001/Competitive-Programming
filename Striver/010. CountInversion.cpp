/*https://www.geeksforgeeks.org/counting-inversions/*/
-----------------------------------------------------------------------
/*
	M1 : Brute Force 
	O(n^2) time and O(1) space
*/
-----------------------------------------------------------------------
/*
	M2 : Fenwick Tree
	O(nlog(max(a[i]))) time and O(max(a[i])) space 
*/
	class BIT{
	public:
	    vector<int> bit;
	    int n;
	    BIT(int n){
	        this->n = n;
	        bit.resize(n+1,0);
	    }
	    void update(int idx, int value){
	        while(idx <= n){
	            bit[idx] += value;
	            idx += (idx & (-idx));
	        }
	    }
	    int pre_sum(int idx){
	        int sum = 0;
	        while(idx > 0){
	            sum += bit[idx];
	            idx -= (idx & (-idx));
	        }
	        return sum;
	    }
	    int range_sum(int l, int r){
	        return pre_sum(r) - pre_sum(l - 1);
	    }
	};

	int solve(vector<int> a){
		int n = a.size();
	    int maxi = 0;
	    for(int i = 0; i < n; i ++) maxi = max(maxi, a[i]); 
	    BIT fen(maxi);
	    long ans = 0;
	    for(int i = n - 1; i >= 0; i --){
	        ans += fen.pre_sum(a[i]-1); 
	        fen.update(a[i],1);
	    }
	    return ans;
	}
-----------------------------------------------------------------------
/*
	M3 : fenwick Tree
	O(nlogn) time and O(n) space
*/
	class BIT{
	public:
	    vector<int> bit;
	    int n;
	    BIT(int n){
	        this->n = n;
	        bit.resize(n+1,0);
	    }
	    void update(int idx, int value){
	        while(idx <= n){
	            bit[idx] += value;
	            idx += (idx & (-idx));
	        }
	    }
	    int pre_sum(int idx){
	        int sum = 0;
	        while(idx > 0){
	            sum += bit[idx];
	            idx -= (idx & (-idx));
	        }
	        return sum;
	    }
	    int range_sum(int l, int r){
	        return pre_sum(r) - pre_sum(l - 1);
	    }
	};
	int solve(vector<int> a){
		int n = a.size();
        vector<int> v = a;
        sort(v.begin(), v.end());
        BIT fen(n);
        long ans = 0;
        for(int i = n - 1; i >= 0; i --){
            int index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            ans += fen.pre_sum(index);
            fen.update(index+1, 1);
        }
        return ans;
	}
-----------------------------------------------------------------------------
/*
	M4 : Merge Sort
	O(nlogn) time and O(n) space 
*/
	long _merge(vector<int>& a, vector<int>& temp, int left, int mid, int right){
        long inv_count = 0;
        int i = left;
        int j = mid;
        int k = left;
        while(i < mid and j <= right){
            if(a[i] <= a[j]){
                temp[k ++] = a[i ++];
            }
            else{
                temp[k ++] = a[j ++];
                inv_count += (mid - i);
            }
        }
        while(i < mid){
            temp[k ++] = a[i ++];
        }
        while(j <= right){
            temp[k ++] = a[j ++];
        }
        for(int i = left; i <= right; i ++)
            a[i] = temp[i];
        return inv_count;
    }

    long merge_sort(vector<int>& a, vector<int>& temp, int left, int right){
        if(left >= right) return 0;
        int mid = (left + right) >> 1; 
        long inv_count = 0;
        inv_count += merge_sort(a, temp, left, mid);
        inv_count += merge_sort(a, temp, mid+1, right);
        inv_count += _merge(a, temp, left, mid + 1, right);
        return inv_count;
    }

	long countInversions(vector<int> a) {
        int n = a.size();
        vector<int> temp(n);
        return merge_sort(a,temp,0,n-1);
	}