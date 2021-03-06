/**
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

int main(int argc, char **argv)
{
	if (argc < 2) {
		cout << "usage:" << argv[0] << " number" << endl;
		return 1;
	}
	Solution itr;
	cout << itr.intToRoman(atoi(argv[1])) << endl;

	return 0;
}

