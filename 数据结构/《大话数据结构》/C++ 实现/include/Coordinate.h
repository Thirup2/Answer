#ifndef COORDINATE_H_
#define COORDINATE_H_

// -----------------------包含头文件-------------------------- //
#include <iostream>
#include <string>

// -----------------------类定义-------------------------- //
class Coordinate
{
    // 友元声明
    friend std::istream &read(std::istream &is, Coordinate &ins);
    friend std::ostream &print(std::ostream &os, Coordinate &ins);
public:
    // 类型成员
    typedef int set;
public:
    // 构造函数
    Coordinate() = default;
    Coordinate(set m, set n) : x(m), y(n) { }
    explicit Coordinate(std::istream &is);
    // 拷贝函数
    Coordinate(const Coordinate &copy) = default;
    // 成员函数
    void changeCoord(set m, set n);
    void changeCoord(const Coordinate &copy);
    bool equals(const Coordinate &compare) const { return (x == compare.x) && (y == compare.y); }
private:
    // 数据成员
    set x = 0;
    set y = 0;
};

// -----------------------非成员函数-------------------------- //
std::istream &read(std::istream &is, Coordinate &ins);
std::ostream &print(std::ostream &os, Coordinate &ins);

#endif