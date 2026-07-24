/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    //遍历到一个数字，就把当前数字送入数值相应的位置,0代表已占用
    for(int i = 0;i < numsSize;i++){
        int index = abs(nums[i]) - 1;  // 注意取绝对值，因为可能已被标记为负
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }    
    }
    int  count = 0;
    for(int i = 0;i<numsSize;i++){//收集
        if(nums[i] > 0){//说明没有对应的数
            nums[count++] = i + 1;
        }
    }
    *returnSize = count;
    return nums;
}