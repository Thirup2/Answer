#include <iostream>
int main(void)
{
    int i=0,&r=i;
    auto a=r;
    const int ci=i,&cr=ci;
    auto b=ci; 
    auto c=cr;
    auto d=&i;
    auto e=&ci;
    auto &g=ci; 
    a=42;
    b=42;
    c=42;
    // d=42;        不能将 "int" 类型的值分配到 "int *" 类型的实体
    // e=42;        不能将 "int" 类型的值分配到 "const int *" 类型的实体
    // g=42;        表达式必须是可修改的左值

    return 0;
}