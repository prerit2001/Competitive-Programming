1.	Check if a number if a power of 2 or not in O(1) 
-> n & n - 1 == 0
2.	Count total set bits 
Given a positive integer A, the task is to count the total number of set bits in the 
binary representation of all the numbers from 1 to A.
-> for every bit pos check pattern of set bit
->  /*int setBit = 0;
      for(int i = 0; i < 32; i ++){
        long power = (1LL << i);
        if(A >= power){
            long divident = power * 2;
            long divisor = A - power + 1;
            long qotient = divisor / divident;
            long remender = divisor % divident;
            setBit += qotient * (power);
            setBit += min(power, remender);
        }
    }
    return setBit;*/
3.	Divide Integers without / operator
// 7 / 3 
//=> 3 <= 10 , 3 * 2 = 6 <= 10,  3 * 4 = 12 >= 10 break -> 2 steps needed
//=> 10 -> 10 - 6 = 4
//=> 3 <= 4 , 3 * 2 = 6 >= 4 break -> 1 steps needed
//=> 4 -> 4 - 3 = 1
//=> 3 >= 1 break -> 0 steps needed
// Total step needed = 2 + 1 + 0 = 3 Ans ===> 7 / 3 = 3 Ans
->class Solution {
public:
    int divide(int dvd, int dvs) {
        if(dvd == -((unsigned)1 << 31) and dvs == -1){
            return ((unsigned)1 << 31) - 1;
        }
        if(dvd == ((unsigned)1 << 31) - 1 and dvs == 1){
            return ((unsigned)1 << 31) - 1;
        }
        if(dvd == -((unsigned)1 << 31) and dvs == 1){
            return -((unsigned)1 << 31);
        }
        if(dvd == ((unsigned)1 << 31) - 1 and dvs == -1){
            return -((unsigned)(1 << 31) - 1);
        }
        int sign = ((dvd > 0) == (dvs > 0)) ? 1 : -1;
        int ans = 0;
        dvd = -abs(dvd); // handle every thing in negative order -> 
        dvs = -abs(dvs);
        while(dvd <= dvs){
            int cnt = 0;
            unsigned int inc = 1;
            unsigned int t = dvs;
            int lastTaken = 0;
            while(t >= dvd){
                lastTaken = t;
                cnt = inc;
                t *= 2;
                inc *= 2;
            }
            dvd -= lastTaken;
            ans += cnt;
        }
        return sign * ans;
    }
};
4.	Power Set 
-> easy 
5. Find LSB in o(1) 
-> n & (n - 1) -> toggle MSB off
-> n xor (n & (n - 1)) => msb
6. Find MSB in O(1)
    ‘N’ = ‘N’ | ‘N’ >> 1.
    ‘N’ = ‘N’ | ‘N’ >> 2.
    ‘N’ = ‘N’ | ‘N’ >> 4.
    ‘N’ = ‘N’ | ‘N’ >> 8.
    ‘N’ = ‘N’ | ‘N’ >> 16.
    ‘N’ = ‘N’ + 1.
    Return, (‘N’ >> 1).
6.	Find square of a number without using multiplication or division operators
-> square(n) = 0 if n == 0
  if n is even 
     square(n) = 4*square(n/2) 
  if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

Examples
  square(6) = 4*square(3)
  square(3) = 4*(square(1)) + 4*1 + 1 = 9
  square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49