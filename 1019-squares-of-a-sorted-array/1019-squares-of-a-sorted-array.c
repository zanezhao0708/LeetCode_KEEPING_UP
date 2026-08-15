int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    int i = 0, j = numsSize - 1;
    for (int p = numsSize - 1; p >= 0; p--) {
        int x = nums[i] * nums[i];
        int y = nums[j] * nums[j];
        if (x > y) {
            ans[p] = x;
            i++;
        } else {
            ans[p] = y;
            j--;
        }
    }
    return ans;
}
