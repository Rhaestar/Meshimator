#include "vector4.hh"
#include <iostream>

namespace Utils
{
    std::ostream& operator<<(std::ostream& os, const Vector4& v)
    {
        return os << v.x << " " << v.y << " " << v.z;
    }
}
