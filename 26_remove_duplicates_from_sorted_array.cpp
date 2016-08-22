/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length. 
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int j = 0;
	    int i = 1; //!nums.empty();
		int size = nums.size();
		int n;
	    for (j = 0; j < size - 1; j++) {
			n = nums[j];
        	if (n > nums[i-1])
            	nums[i++] = n;
		}
	    return i;
	}
};

class MySolution {
public:
	int removeDuplicates(vector<int>& nums) {
		int j = 0;
		int i = 1;
		int flag = 0;
		for (; i < nums.size(); i++) {
			if (nums[i] == nums[j]) {
				flag = 1;
			} else if (flag == 0){
				++j;
			} else {
				j++;
				nums[j] = nums[i];
			}
		}
		return j + 1;
	}
};

int main()
{
	int a[] = {1, 1, 2, 3, 4, 5, 5, 5, 7, 9, 9};
	int len = sizeof(a) / sizeof(*a);

	vector<int> nums(a, a + len);

	MySolution rdfsa;
	cout << rdfsa.removeDuplicates(nums) << endl;

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}
