/**
 * Reverse digits of an integer.
 *
 * Example1: x = 1234, return 4321
 * Example2: x = -1234, return -4321 
 */

#include <iostream>

class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return x;

		bool negative = false;
		int n = x, t;
		int ret = 0;
		if (x < 0) {
			negative = true;
			n = -x;
		}

		while (n > 0) {
			t = n % 10;
			ret = ret * 10 + t;
			n /= 10;
		}

		return (negative ? -ret : ret);
	}
};

int main()
{
	Solution ri;

	int x = -1234;

	std::cout << "before reverse:" << x << std::endl
			  << "after reverse:" << ri.reverse(x) << std::endl;

	return 0;
}
