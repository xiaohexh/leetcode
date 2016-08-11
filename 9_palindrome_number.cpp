/**
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 */

/**
 * condition is 'without extra space',
 * but I don't think it's neccery under real production env.
 */

#include <iostream>
#include <vector>
#include <cstdio>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0) {
			return true;
		}
		
		x = (x < 0) ? -x : x;

		std::vector<int> vdigit;

		while (x > 0) {
			vdigit.push_back(x % 10);
			x /= 10;
		}

		ssize_t size = vdigit.size();

		for (int i = 0; i < size / 2; i++) {
			if (vdigit[i] != vdigit[size - i - 1]) {
				return false;
			}
		}

		return true;
	}
};

int main()
{
	int x = 5678965;

	Solution pn;
	std::cout << (pn.isPalindrome(x) ? true : false) << std::endl;

	return 0;
}
