## 解法1: 双指针
```c
int removeElement(int *nums, int numsSize, int val)
{
    int i = 0, j = 0;
    for (; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
```
- 使用快慢双指针的方法, `i`为慢指针, `j`为快指针, 两者都从零开始
- 当`j`指向的元素不为`val`时, 就将其移动到`i`的位置, 于是将所有非`val`元素按顺序移动到了数组的前端
- 当`j`移动到数组外的时候, `i`的位置刚好是所有满足条件的数组的后一个位置, 所以其值刚好为返回的数组元素个数

### 优化
```c
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
```
- 因为题目未要求返回的数组的元素顺序以及后面部分的元素内容, 所以直接将两个指针分别放在数组的头部和尾部
- 先移动后面的指针, 直到让其指向非`val`的元素, 然后再将前面的指针移动到第一个`val`元素的位置
- 让`nums[i]=nums[j]`, 然后双方往前走一个元素
- 跳出循环后按照注释内容进行判断