int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize < 2) {
        return numsSize;
    }
    int i = 0, j = 0;
    while (j < numsSize) {
        if (nums[j] > nums[i]) {
            nums[++i] = nums[j];
        }
        j++;
    }
    return i + 1;
}