## 解法1: 双指针
```c
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
```
- 使用下标来代替指针
- `i`为慢指针, `j`为快指针
- `j`为0时`i`不动, `j`向前移动一个元素的距离. `j`不为零时将`j`指向的值赋给`i`指向的元素, 二者都向前移动一个元素的距离.
- 当`j`遍历完数组后, `i`的位置刚好是所有非零元素的后一个位置, 后续补零即可

### 变式
```c
void moveZeroes(int *nums, int numsSize)
{
    int i = 0, j = 0;
    int temp;
    while (j != numsSize) {
        if (nums[j] != 0) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
        j++;
    }
}
```
- 将原本后续的循环补零去掉了, 但是将原本的一次赋值操作变成了现在的三次, 并且多使用了一个变量