/**
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 *
 * [
 *	 [1,2,3],
 *	 [1,3,2],
 * 	 [2,1,3],
 *	 [2,3,1],
 *	 [3,1,2],
 *	 [3,2,1]
 * ]
 */

/**
 * 解题思路：
 * 遍历数组中的数字，要求所有数字的排列，只要求得除当前数字外的其他所有数字的排列，然后将当前数字放到第一位即可
 * 举例来说：
 * 1，2，3，4的排列
 * 只要求得2，3，4的排列，要求得2,3，4的排列，只要求得3,4的排列，要求得3,4的排列，只要求得4的排列，结束本轮递归，
 * 在每一轮递归中，需要调换该轮中的第一个数字，让该轮中的每一个数字都有相同的放在第一位的机会（次数）
 */

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {

		    swap(num[begin], num[i]);


		    permuteRecursive(num, begin + 1, result);

		    // reset
		    swap(num[begin], num[i]);

		}
    }

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
};

int main()
{
	int a[] = {1, 2, 3};
	size_t len = sizeof(a) / sizeof(*a);
	vector<int> num(a, a + len);

	Solution per;
	vector<vector<int> > ret = per.permute(num);

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << ",";
		}
		cout << endl;
	}

	return 0;
}
