#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0)
            return cal_mid(nums2);
        if (m == 0)
            return cal_mid(nums1);
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n << 1;
        int l1, r1, l2, r2;
        while (l <= r)
        {
            int mid1 = (l + r) >> 1;
            int mid2 = n + m - mid1;

            l1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) >> 1];
            r1 = mid1 == n << 1 ? INT_MAX : nums1[mid1 >> 1];

            l2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) >> 1];
            r2 = mid2 == m << 1 ? INT_MAX : nums2[mid2 >> 1];

            if (l1 > r2)
                r = mid1 - 1;
            else if (l2 > r1)
                l = mid1 + 1;
            else
                break;
        }
        return (max(l1, l2) + min(r1, r2)) / 2.0;
    }
    double cal_mid(vector<int>& nums) {
        int len = nums.size();
        return (nums[(len - 1) >> 1] + nums[len >> 1]) / 2.0;
    }
};
Solution sl;
int main()
{
    vector<int> a, b;
    a.push_back(1);
    b.push_back(2);
    b.push_back(3);
    printf("%lf\n", sl.findMedianSortedArrays(a, b));
    return 0;
}
