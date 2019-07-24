class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        for (int now = m + n - 1; now >= 0; --now)
        {
            if (i == -1)
            {
                nums1[now] = nums2[j--];
                continue;
            }
            if (j == -1)
            {
                nums1[now] = nums1[i--];
                continue;
            }
            if (nums1[i] > nums2[j])
                nums1[now] = nums1[i--];
            else
                nums1[now] = nums2[j--];
        }
    }
};
