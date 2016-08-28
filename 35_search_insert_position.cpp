/**
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0 
 */

#include <iostream>
#include <vector>
#include <stdlib.h>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class MySolution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int size = nums.size();
		int beg = 0;
		int end = size - 1;
		int mid;
		while (beg <= end) {
			mid = (beg + end) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				beg = mid + 1;
				if (beg > size - 1 || nums[beg] > target) {
					return beg;
				}
			} else {
				end = mid - 1;
				if (end < 0 || nums[end] < target) {
					return end + 1;
				}
			}
		}
	}
};

int main(int argc, char **argv)
{
	int target;

	if (argc < 2) {
		cout << "usage:" << argv[0] << " target_num" <<endl;
		return 1;
	}

	//int a[] = {1, 2, 5, 7, 11, 15};
	int a[] = {1, 3, 5, 6};
	size_t size = sizeof(a) / sizeof(*a);
	vector<int> nums(a, a + size);

	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	target = atoi(argv[1]);

	MySolution si;
	cout << si.searchInsert(nums, target) << endl;

	return 0;
}
