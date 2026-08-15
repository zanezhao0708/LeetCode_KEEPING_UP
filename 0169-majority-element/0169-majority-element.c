int majorityElement(int* nums, int numsSize) {
    int ans = 0, hp = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (hp == 0) {
            ans = x;
            hp = 1;
        } else { 
            hp += x == ans ? 1 : -1;
        }
    }
    return ans;
}
