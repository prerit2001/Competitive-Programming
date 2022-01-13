/*https://www.spoj.com/problems/AGGRCOW/*/
/*
	M1: check maximum possible linearly
	O(n*max(A[i])) time and O(1) space
*/
	bool isCompatible(vector < int > inp, int dist, int cows) {
	  int n = inp.size();
	  int k = inp[0];
	  cows--;
	  for (int i = 1; i < n; i++) {
	    if (inp[i] - k >= dist) {
	      cows--;
	      if (!cows) {
	        return true;
	      }
	      k = inp[i];
	    }
	  }
	  return false;
	}
	int main() {
	  int n = 5, m = 3;
	  vector<int> inp {1,2,8,4,9};
	  sort(inp.begin(), inp.end());
	  int maxD = inp[n - 1] - inp[0];
	  int ans = INT_MIN;
	  for (int d = 1; d <= maxD; d++) {
	    bool possible = isCompatible(inp, d, m);
	    if (possible) {
	      ans = max(ans, d);
	    }
	  }
	  cout << "The largest minimum distance is " << ans << '\n';
	}
/*
	M2: Binary Search
	O(nlogn) time and O(1) space
*/
	bool isPossible(int a[], int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
    }
    int main() {
      int n = 5, cows = 3;
      int a[]={1,2,8,4,9};
      sort(a, a + n);

      int low = 1, high = a[n - 1] - a[0];

      while (low < high) {
        int mid = (low + high + 1) >> 1;

        if (isPossible(a, n, cows, mid)) {
          low = mid;
        } else {
          high = mid - 1;
        }
      }
      cout << "The largest minimum distance is " << low << endl;

      return 0;
    }