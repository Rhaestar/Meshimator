#include "vector3.hh"
#include <cmath>
#include <vector>
#include <iostream>

namespace Utils
{
    std::ostream& operator<<(std::ostream& os, const Vector3& v)
    {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }
}
