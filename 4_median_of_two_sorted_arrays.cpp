/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 *
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

#define min(a, b) ((a) < (b) ? (a) : (b))

double find(int A[],int m,int B[],int n,int del)
{
    if(m == 0) return B[del-1];
    else if (n == 0) return A[del-1];
    else if (del == 1) return min(A[0], B[0]);

    int temp = del / 2;
    if (min(m, n) < temp) {
		temp = min(m, n);
	}

    if(A[temp - 1] >= B[temp - 1]) {
		return find(A, m, B + temp, n - temp, del - temp);
	} else {
		return find(A + temp, m - temp, B, n, del - temp);
	}
}

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int del = (n + m + 1) / 2;
        double temp = find(A, m, B, n, del);
		cout << "temp:" << temp << endl;
        if((m + n) & 1) {
			return temp;
		} else {
			return (find(A, m, B, n, del) + temp) / 2.0;
		}
    }
};

int main()
{
	int A[] = {1, 4, 6, 9, 11};
	int B[] = {2, 3, 6, 10};

	Solution fmsa;
	double ret = fmsa.findMedianSortedArrays(A, 5, B, 4);
	std::cout << ret << std::endl;

	return 0;
}
