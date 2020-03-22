#include "triangle.hh"

namespace Utils
{
    std::ostream& operator <<(std::ostream& o, const Triangle& t)
    {
        //Obj files are 1-indexed;
        return o << t.a + 1 << " " << t.b + 1 << " " << t.c + 1;
    }
}
