#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC target("sse2")
#pragma GCC target("popcnt") // best for bitset
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

const int SZ = 2001;

void functions()
{
	bitset<SZ> bit;
	bit.all(); //checks whether all bits are set or not
	bit.any(); //checks whether >= 1 bit is on
	bit.none(); //checks if all bits are off
	bit.count(); //counts no of set bits
	bit.flip(); //flips all bits
	bit.flip(1); //flips 1st bit
	bit.reset(); //resets all bits to 0
	bit.reset(1); //resets 1st bit
	bit.set(); //sets all bits to 1
	bit.set(1); //sets 1st bit to 1
	bit.size(); //return size of bitset
	bit.test(1); //check if 1st bit is on or not
	cout << bit.to_string(); //converts to string
	cout << bit._Find_first() << "\n"; // 000110000 -> 6, Find first set bit
	cout << bit._Find_next(6) << "\n"; // next set bit in bitset after index 6
}