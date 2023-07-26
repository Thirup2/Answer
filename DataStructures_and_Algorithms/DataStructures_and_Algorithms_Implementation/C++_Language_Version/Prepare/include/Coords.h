#ifndef COORDS_H_
#define COORDS_H_

#include <iostream>

class Coords
{
    friend bool operator==(const Coords &, const Coords &);
    friend bool operator<(const Coords &, const Coords &);
    friend std::istream &operator>>(std::istream &, Coords &);
    friend std::ostream &operator<<(std::ostream &, const Coords &);
public:
    using pos = int;
public:
    Coords();
    Coords(pos n, pos m);
    Coords(const Coords &copied);
    Coords(Coords &&) noexcept;
    ~Coords();
    Coords &operator=(const Coords &copied);
    Coords &operator=(Coords &&copied) noexcept;
private:
    pos x = 0;
    pos y = 0;
};

bool operator==(const Coords &coords1, const Coords &coords2);
bool operator!=(const Coords &coords1, const Coords &coords2);
bool operator<(const Coords &coords1, const Coords &coords2);
bool operator<=(const Coords &coords1, const Coords &coords2);
bool operator>(const Coords &coords1, const Coords &coords2);
bool operator>=(const Coords &coords1, const Coords &coords2);

std::istream &operator>>(std::istream &is, Coords &coords);
std::ostream &operator<<(std::ostream &os, const Coords &coords);

#endif