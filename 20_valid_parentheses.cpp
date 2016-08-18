/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    bool isValid(string s) {
		string::size_type len = s.size();        
		if (len == 0 || len % 2 != 0)
			return false;

		string::size_type i = 0;
		for (; i < len; i += 2) {
			if (s[i] == '(' && s[i + 1] != ')') return false;
			if (s[i] == '[' && s[i + 1] != ']') return false;
			if (s[i] == '{' && s[i + 1] != '}') return false;
		}

		return true;
    }
};

int main()
{
	string s("()[]{}");
	Solution vp;
	cout << vp.isValid(s) << std::endl;

	s = "(]";
	cout << vp.isValid(s) << std::endl;

	s = "([)";
	cout << vp.isValid(s) << std::endl;

	return 0;
}
