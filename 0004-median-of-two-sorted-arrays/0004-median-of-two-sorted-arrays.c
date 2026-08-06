double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double* arr = (double*)malloc(sizeof(double)*(nums1Size+nums2Size));
    int i = 0;
    int c1 = 0,c2=0;
    while(c1 != nums1Size && c2 != nums2Size){//归并
        if(nums1[c1] <= nums2[c2]){
            arr[i++] = nums1[c1++];
        }
        else{
             arr[i++] = nums2[c2++];
        }
    }
    if(c1 == nums1Size){//nums1已经空
    while(c2 < nums2Size){
        arr[i++] = nums2[c2++];
        }
    }
    else{//nums2已经空
        while(c1 < nums1Size){
         arr[i++] = nums1[c1++];
        }
    }
    int total = nums1Size + nums2Size;
    double median;

    if (total % 2 == 1) {
        median = arr[total / 2];
    } else {
        median = (arr[total / 2 - 1] + arr[total / 2]) / 2.0;
    }
    return median;
}