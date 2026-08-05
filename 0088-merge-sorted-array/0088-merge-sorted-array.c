void merge(int* nums1, int nums1Size, int m,
           int* nums2, int nums2Size, int n) {
    int i = m - 1;       // nums1 有效元素末尾
    int j = n - 1;       // nums2 有效元素末尾
    int k = m + n - 1;   // nums1 总数组末尾

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // nums1 剩余元素本来就在正确位置，只需复制 nums2 的剩余元素。
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}