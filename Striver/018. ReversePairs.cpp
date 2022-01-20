/*https://leetcode.com/problems/reverse-pairs/*/
--------------------------------------------------------------------------
/*
    M1 : Using Dynamic Segment Tree
    O(nlogn) time and O(n) space
*/
    typedef long long ll;
    struct Node {
        ll value;
        struct Node *L, *R;
    };
    struct Node* getnode() {
        struct Node* temp = new struct Node;
        temp->value = 0;
        temp->L = NULL;
        temp->R = NULL;
        return temp;
    }
    struct Node* root;
    void UpdateHelper(struct Node* curr, ll index, ll L, ll R, ll delta) {
        if (L > index || R < index) return;
        if (L == R && L == index) {
            curr->value += delta;
            return;
        }
        ll mid = L - (L - R) / 2;
        ll sum1 = 0, sum2 = 0;
        if (index <= mid) {
            if (curr->L == NULL) {
                curr->L = getnode();
            }
            UpdateHelper(curr->L, index, L, mid, delta);
        } else {
            if (curr->R == NULL) {
                curr->R = getnode();
            }
            UpdateHelper(curr->R, index, mid + 1, R, delta);
        }
        if (curr->L) sum1 = curr->L->value;
        if (curr->R) sum2 = curr->R->value;
        curr->value = sum1 + sum2;
        return;
    }

    ll queryHelper(struct Node* curr, ll a, ll b, ll L, ll R) {
        if (curr == NULL) return 0;
        if (L > b || R < a) return 0;
        if (L >= a && R <= b) return curr->value;
        ll mid = L - (L - R) / 2;
        return queryHelper(curr->L, a, b, L, mid) + queryHelper(curr->R, a, b, mid + 1, R);
    }

    ll query(ll L, ll R) { return queryHelper(root, L, R, 1, (1LL << 35)); }

    void update(ll index, ll value) { UpdateHelper(root, index, 1, (1LL << 35), value); }

    ll getNewVal(ll n) {
        return (1LL << 32) + n;
    }

    class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            root = getnode();
            ll n = nums.size();
            int ans = 0;
            for(ll i = 0; i < n; i ++){
                ll larger = getNewVal(2 * (ll)nums[i]) + 1;
                ans += query(larger, (1LL << 35));
                update(getNewVal(nums[i]), 1);
            }
            return ans;
        }
    };
------------------------------------------------------------------------------
/*
    M2 : Using Normal Segment Tree with array elements range comprensions
    O(nlogn) and O(n) space
*/
    typedef long long ll;

    class segTree {
       public:
        ll n;           // size of array
        vector<ll> a;   // 1-index array
        vector<ll> St;  // segTree Storage
        segTree(ll n, vector<ll> a) {
            this->n = n;
            this->a.resize(n + 1, 0);
            for (ll i = 0; i < n; i++) {
                this->a[i + 1] = a[i];
            }
            St.resize(5 * n);
            build(1, 1, n);
        }
        void build(ll Si, ll Ss, ll Se) {
            if (Ss == Se) {
                St[Si] = a[Ss];
                return;
            }
            ll mid = (Ss + Se) >> 1;
            build(2 * Si, Ss, mid);
            build(2 * Si + 1, mid + 1, Se);
            St[Si] = (St[2 * Si] + St[2 * Si + 1]);
        }
        ll query(ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
            if (Qs > Se or Qe < Ss) return 0;
            if (Qs <= Ss and Qe >= Se) return St[Si];
            ll mid = (Ss + Se) >> 1;
            ll lSubTree = query(2 * Si, Ss, mid, Qs, Qe);
            ll rSubTree = query(2 * Si + 1, mid + 1, Se, Qs, Qe);
            return (lSubTree + rSubTree);
        }
        void update(ll Si, ll Ss, ll Se, ll q, ll val) {
            a[q] = val;
            if (Ss == Se) {
                St[Si] = a[Ss];
                return;
            }
            ll mid = (Ss + Se) >> 1;
            if (Ss <= q and q <= mid)
                update(2 * Si, Ss, mid, q, val);
            else
                update(2 * Si + 1, mid + 1, Se, q, val);
            St[Si] = (St[2 * Si] + St[2 * Si + 1]);
        }
    };

    class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            ll n = nums.size();
            map<ll, ll> mp;
            for(int &num : nums){
                mp[num] = 1;
            }
            int cnt = 1;
            for(auto &[u, v]: mp){
                v = cnt ++;
            }
            vector<ll> a(1e5 * 2LL, 0);
            segTree seg(n, a);
            int ans = 0;
            for(int &num : nums){
                auto it = mp.upper_bound(2LL * num);
                if(it != mp.end()){
                    ans += seg.query(1, 1, n, it -> second, 1e5);
                }
                a[mp[num]] ++;
                seg.update(1, 1, n, mp[num], a[mp[num]]);
            }
            return ans;
        }
    };
------------------------------------------------------------------------------
/*
    M3 : Merge Sort Variation
    O(nlogn) time and O(1) space  
*/

    class Solution {
    public:
        int mergesort(int l, int r, vector<int>&arr, vector<int>&temp){
            if(l>=r){
                return 0;
            }
            int mid = l+((r-l)/2);
            int ans = mergesort(l, mid, arr, temp);
            ans += mergesort(mid+1, r, arr, temp);
            ans += merge(l, r, arr, temp);
            return ans;
        }
        int merge(int l, int r, vector<int>&arr, vector<int>&temp){
            int mid = l+((r-l)/2);
            int i=l, j=mid+1, k=l;
            int ans=0;
            while(i<=mid && j<=r){
                if(arr[i]/2+max(0,arr[i]%2)<=arr[j]){
                    i++;
                }
                else{
                    ans+=mid-i+1;
                    j++;
                }
            }
            i=l;
            j=mid+1;
            while(i<=mid && j<=r){
                if(arr[i]<arr[j]){
                    temp[k++]=arr[i++];
                }
                else{
                    temp[k++]=arr[j++];
                }
            }
            while(i<=mid){
                temp[k++]=arr[i++];
            }
            while(j<=r){
                temp[k++]=arr[j++];
            }
            for(int idx=l; idx<=r; idx++){
                arr[idx]=temp[idx];
            }
            return ans;
        }
        int reversePairs(vector<int>& nums) {
            int n = nums.size();
            vector<int>temp(n);
            return mergesort(0, n-1, nums, temp);
        }
    };
-----------------------------------------------------------------------------