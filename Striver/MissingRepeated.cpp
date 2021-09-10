/*https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/*/
-----------------------------------------------------------------------------
/*
	M1 : use hash maps or auxilary arrays to store frequency and filter solution
	O(n) time and O(n) space
*/
-----------------------------------------------------------------------------
/*
	M2 : index negative approach
	O(n) time and O(n) space
*/
	void solve(vector<int> a, int n){
		for(int i = 0; i < n; i ++){
			if(a[abs(a[i]) - 1] >= 0) a[abs(a[i]) - 1] *= -1;
			else cout << "Repeated Number : " << abs(a[i]) << '\n'; 
		}
		for(int i = 0; i < n; i ++){
			if(a[i] > 0) cout << "Missing Number : " << i + 1 << '\n';
		}
	}
------------------------------------------------------------------------------
/*
	M3 : build two eqation two variables and solve them
	O(n) time and O(1) space
	
	Approach : 
		EQ1 : Get the sum of all numbers using formula S = n(n+1)/2 – x + y
		EQ2 : Get product of all numbers using formula P = 1*2*3*…*n * y / x

	Cons: 
		Might cause Airthmatice overflows
*/
------------------------------------------------------------------------------
/*
	M4 : Use XOR techinique
	O(n) time and O(1) space

	Approach : 
		let missing number be X and repeating number be Y
		let xor of array = xor_arr
		now (xor_arr ^ (1^2^3..n)) = X ^ Y
		now X ^ Y must have one bit set
		now divide the array element into two buckets b1 and b2
		b1 will contains yth bit set in both (X ^ Y) and arr[i]
		b2 will contains yth bit not set in both (X ^ Y) and arr[i]
		Also b1 will contains yth bit set in both (X ^ Y) and (1 <= i <= n)
		Also b2 will contains yth bit not set in both (X ^ Y) and (1 <= i <= n)
		xor elements of buckets let it be xor_b1 and xor_b2
		now xor_b1 and xor_b2 are the X and Y required
		but to find which is missing and which is repeating we must do a simple linear seaarch


	Eg : 	[4,3,6,2,1,1]
			X^Y = (4^3^6^2^1^1) ^ (1^2^3^4^5^6) = 4 = bin(100) 
			b1 = [4,6] + [4,5,6]
			b2 = [1,1,2,3] + [1,2,3]
			xor_b1 = 5
			xor_b2 = 1
			linear searching to find X = 5 and Y = 1 

*/

	/* O(1) time for xor 1 to n
	int xor_from_1_to_n(int n){
		if(n % 4 == 0) return n;
		if(n % 4 == 1) return 1;
		if(n % 4 == 2) return n + 1;
		if(n % 4 == 3) return 0;
	}*/

	void solve(vector<int> a, int n){
		int xor_arr = 0;
		for(int i = 0; i < n; i ++) xor_arr ^= a[i];
		for(int i = 1; i <= n; i ++) xor_arr ^= i;
		int b1 = 0, b2 = 0;
		int last_set_bit_xor_arr = (xor_arr) ^ ((xor_arr) & (xor_arr - 1));
		for(int i = 0; i < n; i ++){
			if(a[i] & last_set_bit_xor_arr) b1 ^= a[i];
			else b2 ^= a[i];
		}
		for(int i = 1; i <= n; i ++){
			if(i & last_set_bit_xor_arr) b1 ^= i;
			else b2 ^= i;
		}
		int cntb1 = 0, cntb2 = 0;
		for(int i = 0; i < n; i ++){
			if(a[i] == b1) cntb1 ++;
			if(a[i] == b2) cntb2 ++;
		}
		if(cntb1 == 0){
			cout << "Repeated Number : " << b2 << '\n';
			cout << "Missing Number : " << b1 << '\n';
		}
		else{
			cout << "Repeated Number : " << b1 << '\n';
			cout << "Missing Number : " << b2 << '\n';
		}
	}