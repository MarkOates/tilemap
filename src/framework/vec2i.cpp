

#include <framework/vec2i.hpp>


vec2i::vec2i(int x, int y)
   : x(x)
   , y(y)
{
}


vec2i::~vec2i()
{
}


bool vec2i::operator==(const vec2i &other) const
{
   return x == other.x && y == other.y;
}


bool vec2i::operator!=(const vec2i &other) const
{
   return !(*this == other);
}


