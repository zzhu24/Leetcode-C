double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int * result = (int *)malloc(sizeof(int) * (total + 1));
    int a = 0;
    int b = 0;
    int i = 0;
    for(; a != nums1Size && b != nums2Size; i++){
        if(nums1[a] < nums2[b]){
            result[i] = nums1[a];
            a = a + 1;
        }
        else{
            result[i] = nums2[b];
            b = b + 1;
        }
    }
    if(a != nums1Size){
        for(;i < total; i++){
            result[i] = nums1[a];
            a++;
        }
    }
    if(b != nums2Size){
        for(;i < total; i++){
            result[i] = nums2[b];
            b++;
        }
    }
    if(total % 2 == 1){
        return (double)result[total/2];
    }
    else{
        return ((double)result[total/2 - 1] + (double)result[total/2]) / 2;
    }
}