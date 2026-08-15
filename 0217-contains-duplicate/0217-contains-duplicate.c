int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(nums[0]), cmp); //排序
    for(int i=0; i < numsSize-1; ++i){			//遍历
        if(nums[i] == nums[i+1])					//存在重复元素
        	return true;
    }
    return false;
}
