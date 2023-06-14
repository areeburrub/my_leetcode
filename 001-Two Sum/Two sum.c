#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    
    for(int i = 0 ; i <= numsSize ; i++){
        for(int j = 0; j <= numsSize ; j++){
            int* result = malloc(2*sizeof(int));
            if(nums[i]+nums[j] == target){
                result[0] = i;
                result[1] = j; 
                return result;
            }
        }
    }
    return 0;
}

int main(){
    int nums[] = {2,7,11,15};
    int target = 9;
    int returnSize = 0;
    int* result = twoSum(nums,4,target,&returnSize);
    printf("%d %d",result[0],result[1]);
    return 0;
}