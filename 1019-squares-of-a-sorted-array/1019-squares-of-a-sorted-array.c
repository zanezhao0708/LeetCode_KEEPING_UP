/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sort(int *nums,int left,int right){
    if(left >= right )return ;
    
    int pviot = nums[left];
    int i = left;
    int j = right;

    while(i < j){
        while(i < j && pviot <= nums[j])j--;
        while(i < j && pviot >= nums[i])i++;
        if(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    nums[left] = nums[i];
    nums[i] = pviot;

    sort(nums,left,i-1);
    sort(nums,i+1,right);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for(int i = 0;i < numsSize;i++){
        nums[i] = nums[i] * nums[i];
    }
    sort(nums,0,numsSize-1);
    *returnSize = numsSize;
    return nums; 
}