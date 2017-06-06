/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *to_return = (int *)malloc(2*sizeof(int));
    for(int i = 0; i < numsSize-1; i++){
        for(int j = i+1; j < numsSize; j++){
            if((nums[i]+nums[j]) == target){
                to_return[0] = i;
                to_return[1] = j;
                return to_return;
            }
        }
    }
    return NULL;
}