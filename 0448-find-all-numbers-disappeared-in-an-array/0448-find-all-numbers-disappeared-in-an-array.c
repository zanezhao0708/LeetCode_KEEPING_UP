/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(int i;i < numsSize ; i++){
        arr[i] = 1;
    }
    for(int i;i < numsSize ; i++){
        arr[nums[i]-1] = 0;
    }
    int* ans = (int*)malloc(sizeof(int)*numsSize);
    int count = 0;
    for(int i;i < numsSize ; i++){
        if(arr[i]){
            ans[count++] = i + 1; 
        }
    }
    *returnSize = count;
    return ans;

}