/**
 *
 *
 */

#include <iostream>
#include <map>
#include <string>
using std::map;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	int romanToInt(string s) {
		int i;

		map<char, int> roman_dict;
		roman_dict['I'] = 1;
		roman_dict['V'] = 5;
		roman_dict['X'] = 10;
		roman_dict['L'] = 50;
		roman_dict['C'] = 100;
		roman_dict['D'] = 500;
		roman_dict['M'] = 1000;

		map<char, int> roman_ixc;
		roman_ixc['I'] = 5;
		roman_ixc['X'] = 50;
		roman_ixc['C'] = 500;

    	int value = 0;
		string rs;
		rs.assign(s.rbegin(), s.rend());

    	for (i = 0; i < rs.size(); i++) {
        	if (roman_ixc.find(rs[i]) != roman_ixc.end() && value >= roman_ixc[rs[i]]) {
            	value -= roman_dict[rs[i]];
			} else {
            	value += roman_dict[rs[i]];
			}
		}
    	return value;
	}
};

int main()
{
	Solution rti;
	cout << rti.romanToInt("LXXXIX") << endl;
	return 0;
}
