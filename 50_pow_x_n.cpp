/**
 * Implement pow(x, n).
 */

#include <iostream>
using std::cout;
using std::endl;

class MySolution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;

		return x * myPow(x, n - 1);
	}
};

int main()
{
	MySolution mp;
	cout << mp.myPow(2, 3) << endl;

	return 0;
}
