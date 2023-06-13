#define EXPORT

#include "Coords.h"

Coords::Coords() = default;
Coords::Coords(pos n, pos m) : x(n), y(m) { }
Coords::Coords(const Coords &copied) = default;
Coords::Coords(Coords &&) noexcept =default;
Coords::~Coords() = default;
Coords &Coords::operator=(const Coords &copied) = default;
Coords &Coords::operator=(Coords &&copied) noexcept =default;

bool operator==(const Coords &coords1, const Coords &coords2)
{
    return coords1.x == coords2.x && coords1.y == coords2.y;
}
bool operator!=(const Coords &coords1, const Coords &coords2)
{
    return !(coords1 == coords2);
}
bool operator<(const Coords &coords1, const Coords &coords2)
{
    return (coords1.x < coords2.x) || ((coords1.x == coords2.x) && (coords1.y < coords2.y));
}
bool operator<=(const Coords &coords1, const Coords &coords2)
{
    return coords1 < coords2 || coords1 == coords2;
}
bool operator>(const Coords &coords1, const Coords &coords2)
{
    return !(coords1 <= coords2);
}
bool operator>=(const Coords &coords1, const Coords &coords2)
{
    return !(coords1 < coords2);
}

std::istream &operator>>(std::istream &is, Coords &coords)
{
    return is >> coords.x >> coords.y;
}
std::ostream &operator<<(std::ostream &os, const Coords &coords)
{
    return os << '(' << coords.x << ", " << coords.y << ')';
}