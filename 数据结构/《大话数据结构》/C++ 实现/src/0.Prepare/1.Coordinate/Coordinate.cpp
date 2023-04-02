#include "Coordinate.h"

// 构造函数
Coordinate::Coordinate(std::istream &is)
{
    read(is, *this);
}

// 成员函数
void Coordinate::changeCoord(set m, set n)
{
    x = m;
    y = n;
}
void Coordinate::changeCoord(const Coordinate &copy)
{
    x = copy.x;
    y = copy.y;
}

// 非成员函数
std::istream &read(std::istream &is, Coordinate &ins)
{
    is >> ins.x >> ins.y;
    return is;
}
std::ostream &print(std::ostream &os, Coordinate &ins)
{
    os << "(" << ins.x << ", " << ins.y << ")";
    return os;
}