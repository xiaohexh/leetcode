/**
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <string>
#include <set>
#include <map>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {

		std::map<std::string, int> seqmap;
		std::string seq;
		int count = 0;
		int i, j;

		for (i = 0; i < s.size() - 1; i++) {

			std::set<char> chset;

			chset.insert(s[i]);
			seq += s[i];
			count++;

			for (j = i + 1; j < s.size(); j++) {
				if (!chset.insert(s[j]).second) {
					seqmap.insert(std::make_pair(seq, count));
					count = 0;
					seq = "";

					continue;
				}
				seq += s[j];
				count++;
			}
		}

		/* TODO: here only find one longest substring if there exist more than one */
		std::map<std::string, int>::iterator it = seqmap.begin();
		std::map<std::string, int>::iterator longest_it = it;
		while (it != seqmap.end()) {
			if (longest_it->second < it->second) {
				longest_it = it;
			}
			it++;
		}

		std::cout << "longest substring:" << std::endl;
		std::cout << longest_it->first << " " << longest_it->second << std::endl;
	}
};

int main()
{
	std::string s = "abcadcbb";
	std::cout << s << std::endl;

	Solution lsrc;
	lsrc.lengthOfLongestSubstring(s);

	return 0;
}
