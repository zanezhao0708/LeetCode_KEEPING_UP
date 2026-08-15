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


int thirdMax(int* nums, int numsSize) {
    sort(nums,0,numsSize-1);
    if(numsSize < 3)return nums[numsSize-1];
    int flag = 2;
    int i = numsSize-1;
    while(flag){
        if(i == 0)return nums[numsSize-1];
        i--;
        if(nums[i] != nums[i+1])flag--;
    }
    return nums[i];
}