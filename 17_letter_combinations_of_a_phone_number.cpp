/**
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * 1:* / 2:abc / 3:def / 4:ghi / 5:jkl / 6:mno / 7:pqrs / 8:tuv / 9:wxyz
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::map<char, std::string> digit_letters_m;
        digit_letters_m.insert(std::make_pair('1', "*"));
        digit_letters_m.insert(std::make_pair('2', "abc"));
        digit_letters_m.insert(std::make_pair('3', "def"));
        digit_letters_m.insert(std::make_pair('4', "ghi"));
        digit_letters_m.insert(std::make_pair('5', "jkl"));
        digit_letters_m.insert(std::make_pair('6', "mno"));
        digit_letters_m.insert(std::make_pair('7', "pqrs"));
        digit_letters_m.insert(std::make_pair('8', "tuv"));
        digit_letters_m.insert(std::make_pair('9', "wxyz"));

		std::vector<std::string> ret;
		/* focus on algorithm, input is valid by default */
		std::string first_digit = digit_letters_m[digits[0]];
		std::string second_digit = digit_letters_m[digits[1]];

		std::string tmp;
		for (int i = 0; i < first_digit.size(); i++) {
			tmp = first_digit[i];
			for (int j = 0; j < second_digit.size(); j++) {
				tmp += second_digit[j];
				ret.push_back(tmp);
				tmp = first_digit[i];
			}
		}

		return ret;
	}
};

int main()
{
	std::vector<std::string> ret;

    Solution lcpn;
    ret = lcpn.letterCombinations("45");

	for (int i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << std::endl;
	}

    return 0;
}
