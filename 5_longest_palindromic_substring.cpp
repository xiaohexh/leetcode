/**
 *Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 */

/**
 * This implementation is so ugly, because its run time complexity is O(n^3)
 * but I do not know a better algorithm, maybe I will improve it when I have time.
 * -- by Chris.Xiao
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string::size_type i, j, k, h;
        std::vector<std::string> ret;
        std::string::size_type size = s.size();
        for (i = 0; i < size; i++) {

            for (h = size-1; h > i; h--) {

            	j = i;
				k = h;
                std::string tmp;
                while (k > j && s[k] == s[j]) {
                    tmp += s[j];
                    k--;
                    j++;
                }

                if (k < j) {
                    std::string reverse;
                    reverse.assign(tmp.rbegin(), tmp.rend());
                    tmp += reverse;
                    ret.push_back(tmp);
                }
            }
        }

        std::vector<std::string>::iterator it = ret.begin();
        std::string::size_type max_len = it->size();
        std::string max_str = *it;

		std::cout << "All palindrome substring:" << std::endl;

        for (; it != ret.end(); it++) {
            std::cout << *it << std::endl;
            if (max_len < it->size()) {
                max_len = it->size();
                max_str = *it;
            }
        }

        return max_str;
    }
};

int main()
{
    /* stri'joyyoj'ostream"stringabbagnirts"joyjd */
    std::string s("strijoyyojostreamstringabbagnirtsjoysjd");
	std::cout << "origin string: " << s << std::endl;

    Solution lps;

    std::cout << "Longest palindrome substring: " << lps.longestPalindrome(s) << std::endl;

    return 0;
}
