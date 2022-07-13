#include <vector>
typedef int matrix;

// 比较两个matrix类对象是否相同, 相同返回true, 否则返回false
bool compare(matrix &a, matrix &b);

// 将一个int的vector中迭代器处的值更改为val
vector<int>::iterator change_val(int val, vector<int>::iterator pos);