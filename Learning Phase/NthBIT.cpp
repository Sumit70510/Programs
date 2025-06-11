// CPP program to find k-th bit from right
#include <bits/stdc++.h>
using namespace std;

void printKthBit(unsigned int n, unsigned int k)
{
	cout << ((n & (1 << (k - 1))) >> (k - 1));
}

// Driver Code
int main()
{
	unsigned int n = 2, k = 1;

	// Function Call
	printKthBit(n, k);
	return 0;
}
