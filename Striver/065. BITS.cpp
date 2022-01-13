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
->
4.	Power Set 
-> easy 
5. Find MSB in o(1) 
->
6.	Find square of a number without using multiplication or division operators
->