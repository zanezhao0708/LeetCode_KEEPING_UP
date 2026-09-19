int pivotIndex(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0 ;i<numsSize;i++){
        sum +=nums[i];
    }
    int cur = 0;
    for(int i = 0;i < numsSize;i++){
        if(cur == (sum-nums[i]-cur))return i;
        cur += nums[i];
    }
    return -1;

}