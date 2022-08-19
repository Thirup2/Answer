## 解法1: 双指针
```c
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize < 2) {
        return numsSize;
    }
    int val = nums[0];
    int i = 1, j = 1;
    while (j < numsSize) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            val = nums[j];
            i++;
        }
        j++;
    }
    return i;
}
```
- 首先元素个数为1的肯定返回1
- 对于元素个数大于1的, 至少有第一个元素是不重复的, 所以`i`和`j`从第二个元素开始, 之前要保存好第一个元素的值
- 然后每次判断`j`的值, 如果`j`和保存的`val`相同, 则将`j`向后移, 一直将`j`滑到`!=val`的位置
- 然后给`i`位置赋值, 之后`i`移向下一个位置
- 然后一直重复操作, 直到`j`移出数组
- `i`停留的位置刚好是不重复的元素个数

### 优化
```c
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
```
- 通过数组按升序排列这个条件可以去掉`val`这个变量, 而且省去了每次更新`val`的消耗
- `i`和`j`都从0开始, 当检测到`j`指向的值比`i`指向的值大时, 就先递增`i`, 然后给`i`所在的位置赋值, 否则一直滑动`j`直到其指向的值大于`i`指向的值
- `i`每次停留的位置刚好是最后一个不重复元素所在的位置, 直接返回`i+1`即可