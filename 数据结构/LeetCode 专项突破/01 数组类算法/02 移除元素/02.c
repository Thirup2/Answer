int removeElement(int *nums, int numsSize, int val)
{
    if (!numsSize) {
        return 0;
    }
    int i = 0, j = numsSize - 1;
    while (i < j) {
        if (nums[j] == val) {
            j--;
        } else {
            if (nums[i] == val) {
                nums[i] = nums[j];
                j--;
            }
            i++;
        }
    }
    /*
    ** 出循环的情况有两种:
    ** 1. j跑到i前面去了, 这种情况只有nums[i]被修改了才可能.
    **    此时, i的值正好就是剩下的元素个数
    ** 2. j和i相同了, 如果是移动j导致的结果, 则还必须检验
    **    该位置的值
    */
    if (j == i) {
        if (nums[i] != val) {
            return i + 1;
        }
    }
    return i;
}