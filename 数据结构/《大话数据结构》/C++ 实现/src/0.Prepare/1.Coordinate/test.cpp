#include "Coordinate.h"

std::ostream &showCoord(std::ostream &os, const char *name, Coordinate &coord);

int main()
{
    Coordinate::set x, y;
    // 测试默认构造函数
    Coordinate c1;
    showCoord(std::cout, "c1", c1);
    // 测试输入两个值的构造函数
    std::cin >> x >> y;
    Coordinate c2(x, y);
    showCoord(std::cout, "c2", c2);
    // 测试参数为输入流的构造函数
    Coordinate c3(std::cin);
    showCoord(std::cout, "c3", c3);
    // 测试默认拷贝函数
    Coordinate c4(c1);
    showCoord(std::cout, "c4", c4);
    // 测试拷贝赋值函数
    c2.changeCoord(c3);
    // 测试输入两个值的赋值函数
    std::cin >> x >> y;
    c1.changeCoord(x, y);
    // 输出
    showCoord(std::cout, "c1", c1);
    showCoord(std::cout, "c2", c2);
    showCoord(std::cout, "c3", c3);
    showCoord(std::cout, "c4", c4);
    // 测试相等性判断函数
    if (c1.equals(c2)) {
        std::cout << "c1 == c2" << std::endl;
    }
    if (c1.equals(c3)) {
        std::cout << "c1 == c3" << std::endl;
    }
    if (c1.equals(c4)) {
        std::cout << "c1 == c4" << std::endl;
    }
    if (c2.equals(c3)) {
        std::cout << "c2 == c3" << std::endl;
    }
    if (c2.equals(c4)) {
        std::cout << "c2 == c4" << std::endl;
    }
    if (c3.equals(c4)) {
        std::cout << "c3 == c4" << std::endl;
    }

    return 0;
}
std::ostream &showCoord(std::ostream &os, const char *name, Coordinate &coord)
{
    os << name << " = ";
    print(os, coord) << std::endl;
    return os;
}