#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> ivec;
    ivec.push_back(42);
    /*
    ** 不能使用下标为不存在的元素赋值
    ** 下标只能用来访问存在的元素
    */

    return 0;
}