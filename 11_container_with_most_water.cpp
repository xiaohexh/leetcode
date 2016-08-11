/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water. 
 */

#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int max_area = 0;
		int left = 0, right = height.size() - 1;

		while (left < right) {
			max_area = MAX(max_area, MIN(height[left], height[right]) * (right - left));
			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return max_area;
	}
};

int main()
{
	int a[] = {1, 3, 2, 4, 3};
	std::vector<int> height(a, a + 5);

	Solution cwmw;
	std::cout << cwmw.maxArea(height) << std::endl;

	return 0;
}
