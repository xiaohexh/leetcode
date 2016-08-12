/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {

		std::string ret;

		if (strs.size() == 0) {
			return ret;
		}

		std::vector<std::string>::size_type i;
		std::string::size_type min_size = strs[0].size();
		for (i = 1; i < strs.size(); i++) {
			min_size = (min_size > strs[i].size()) ? strs[i].size() : min_size;
		}

		if (min_size == 0) {
			return ret;
		}

		std::string::size_type j;
		for (j = 0; j < min_size; j++) {
			i = 0;
			char t = strs[i][j];
			for (i = 1; i < strs.size(); i++) {
				if (t != strs[i][j]) {
					return ret;
				}
			}
			ret += t;
		}
		
		return ret;
	}
};

int main()
{
	std::string sa[] = {"abbjoyjd", "abbjoyxjd", "abbjoystringjd", "abbjoyiostreamjd", "abbjoyabcjd"};

	std::vector<std::string> strs(sa, sa + 5);

	Solution lcp;
	std::cout << lcp.longestCommonPrefix(strs) << std::endl;

	return 0;
}
