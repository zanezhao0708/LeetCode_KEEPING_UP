int majorityElement(int* nums, int numsSize) {
    int ans = 0, n = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (n == 0) {
            ans = x;
            n = 1;
        } else { 
            n += x == ans ? 1 : -1;
        }
    }
    return ans;
}
