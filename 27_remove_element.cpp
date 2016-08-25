/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

class MySolution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t size = nums.size();
        size_t i = 0;
        size_t j = size - 1;
        for (; i < j; ++i) {

            if (nums[i] == val) {

                for (; j > i; j--) {
                    if (nums[j] != val)
                        break;
                }

                if (j == i) {
                    return i;
                }

                swap(nums[i], nums[j]);
            }
        }
    }
};

int main()
{
    //int a[] = {3, 3};
    //int a[] = {3, 2, 2, 3};
    //int a[] = {3, 2, 1, 4, 3, 2, 3};
    int a[] = {2, 3, 2, 5, 2, 3, 8};
    //int a[] = {3, 3, 3, 3};
    size_t len = sizeof(a) / sizeof(*a);

    vector<int> nums(a, a + len);
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    MySolution rm;
    cout << rm.removeElement(nums, 3) << endl;

    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
