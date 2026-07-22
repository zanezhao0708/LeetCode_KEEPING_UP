/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    * returnSize = numsSize;
    int front = 0;
    int rear = numsSize -1;
    while(front < rear){
        while(nums[front]%2 == 0 && front < numsSize -1){//前指针如果是偶数就前进，遇到奇数停下
            front++; 
        }
        while(nums[rear]%2 == 1 && rear > 0){//后指针如果是奇数就前进，遇到偶数停下
            rear--;
        }
        if(front < rear){//交换指针内容，保证是指针有序下交换
            int temp = nums[front];
            nums[front] = nums[rear];
            nums[rear] = temp;
        }
    }
    return nums;
}