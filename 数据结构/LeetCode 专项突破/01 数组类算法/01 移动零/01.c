void moveZeroes(int *nums, int numsSize)
{
    int i = 0, j = 0;
    while (j != numsSize) {
        if (nums[j] != 0) {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    for (; i != numsSize; i++) {
        nums[i] = 0;
    }
}