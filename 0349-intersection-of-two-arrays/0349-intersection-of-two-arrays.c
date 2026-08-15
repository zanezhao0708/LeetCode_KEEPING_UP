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

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    sort(nums1,0,nums1Size-1);
    sort(nums2,0,nums2Size-1);
    int i = 0;
    int j = 0;
    int len = 0;
    int* ans = malloc(sizeof(int) * 1000);

    while(i < nums1Size && j < nums2Size){
        if(i < nums1Size && j < nums2Size && nums1[i] == nums2[j]){//两者元素一致
            ans[len] = nums1[i];//装入元素
            while(i < nums1Size && nums1[i] == ans[len])i++;
            while(j < nums2Size && nums2[j] == ans[len])j++;
            len++;
            continue;
        }
        
        if(i < nums1Size && j < nums2Size && nums1[i] > nums2[j]){//数组2更小，j向后移动
            int flag = nums2[j];
            while(j < nums2Size && nums2[j] == flag)j++;
        }
        else{
            int flag = nums1[i];
            while(i < nums1Size && nums1[i] == flag)i++;
        }
    }
    *returnSize = len;
    return ans;
}