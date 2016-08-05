/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,

 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {

		std::vector<int> ret;
		int sum;
		size_t size = nums.size();
		int i = 0, j = size - 1;

		while(i < j) {
			sum = nums[i] + nums[j];
			if (sum == target) {
				ret.push_back(i);
				ret.push_back(j);
				return ret;
			} else if (sum < target) {
				i++;
			} else {
				j--;
			}
		}
		return ret;
    }
};

int main()
{
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	Solution ts;

	std::vector<int> ret = ts.twoSum(nums, 26);
	for (int i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
