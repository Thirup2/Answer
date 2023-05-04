#ifndef COORDINATE_H_
#define COORDINATE_H_

// -----------------------包含头文件-------------------------- //
#include <iostream>

// -----------------------类定义-------------------------- //
class Coordinate
{
    friend bool operator==(const Coordinate &cor1, const Coordinate &cor2);
    friend bool operator!=(const Coordinate &cor1, const Coordinate &cor2);
    friend bool operator<(const Coordinate &cor1, const Coordinate &cor2);
    friend bool operator<=(const Coordinate &cor1, const Coordinate &cor2);
    friend bool operator>(const Coordinate &cor1, const Coordinate &cor2);
    friend bool operator>=(const Coordinate &cor1, const Coordinate &cor2);
    friend std::ostream &operator<<(std::ostream &os, Coordinate &coord);
    friend std::istream &operator>>(std::istream &is, Coordinate &coord);
private:
    using set = int;
private:
    set x = 0;
    set y = 0;
public:
    // 构造
    Coordinate() = default;
    Coordinate(set m, set n) : x(m), y(n) { }
    // 拷贝控制
    Coordinate(const Coordinate &copy) = default;
    ~Coordinate() = default;
    Coordinate &operator=(const Coordinate &copy) = default;
};

// -----------------------非成员函数-------------------------- //
bool operator==(const Coordinate &cor1, const Coordinate &cor2);
bool operator!=(const Coordinate &cor1, const Coordinate &cor2);
bool operator<(const Coordinate &cor1, const Coordinate &cor2);
bool operator<=(const Coordinate &cor1, const Coordinate &cor2);
bool operator>(const Coordinate &cor1, const Coordinate &cor2);
bool operator>=(const Coordinate &cor1, const Coordinate &cor2);
std::ostream &operator<<(std::ostream &os, Coordinate &coord);
std::istream &operator>>(std::istream &is, Coordinate &coord);

// -----------------------非成员函数定义-------------------------- //
inline bool operator==(const Coordinate &cor1, const Coordinate &cor2)
{
    return ((cor1.x == cor2.x) && (cor1.y == cor2.y));
}
inline bool operator!=(const Coordinate &cor1, const Coordinate &cor2) { return !(cor1 == cor2); }
inline bool operator<(const Coordinate &cor1, const Coordinate &cor2)
{
    return (cor1.x < cor2.x) || ((cor1.x == cor2.x) && (cor1.y < cor2.y));
}
inline bool operator<=(const Coordinate &cor1, const Coordinate &cor2) { return ((cor1 < cor2) || (cor1 == cor2)); }
inline bool operator>(const Coordinate &cor1, const Coordinate &cor2) { return !(cor1 <= cor2); }
inline bool operator>=(const Coordinate &cor1, const Coordinate &cor2) { return !(cor1 < cor2); }
inline std::ostream &operator<<(std::ostream &os, Coordinate &coord)
{
    return os << "(" << coord.x << ", " << coord.y << ")";
}
std::istream &operator>>(std::istream &is, Coordinate &coord)
{
    is >> coord.x >> coord.y;
    if (!is) {
        coord = Coordinate();
    }
    return is;
}
#endif