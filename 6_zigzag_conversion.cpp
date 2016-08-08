/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {

		std::string ret;
		int i, j;
		int ori_inter, max_inter, last_inter;
		std::vector<std::vector<char> > chvec;
		int len = s.size();

		chvec.reserve(numRows);

		ori_inter = 2 * numRows - 2;
		max_inter = ori_inter;

		for (i = 0; i < numRows; i++) {
			j = i;
			chvec[i].push_back(s[j]);

			if (i == 0 || i == numRows - 1) {
				j += ori_inter;
				while (j < len) {
					chvec[i].push_back(s[j]);
					j += ori_inter;
				}
			} else {
				last_inter = max_inter;
				j += last_inter;
				while (j < len) {
					chvec[i].push_back(s[j]);
					last_inter = ori_inter - last_inter;
					j += last_inter;
				}
			}

			max_inter -= 2;
		}

		for (i = 0; i < numRows; i++) {
			for (j = 0; j < chvec[i].size(); j++) {
				ret += chvec[i][j];
			}
		}

		return ret;
    }
};

int main()
{
	std::string s = "PAYPALISHIRING";
	int numRows = 3;

	Solution zzc;

	std::cout << zzc.convert(s, numRows) << std::endl;

	return 0;
}
