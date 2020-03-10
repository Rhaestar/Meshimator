#include "triangle.hh"

namespace Utils
{
    std::ostream& operator <<(std::ostream& o, const Triangle& t)
    {
        return o << "(" << t.a << ", " << t.b << ", " << t.c << ")";
    }
}
