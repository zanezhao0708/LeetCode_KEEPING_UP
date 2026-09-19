int majorityElement(int* nums, int numsSize) {
    int ans = 0;
    int n = 0;
    for(int i = 0;i<numsSize;i++){
        if(n == 0){
            ans = nums[i];
            n++;
        }
        else{
            if(nums[i] != ans)n--;
            else n++;
        }
    }
    return ans;
    
}
