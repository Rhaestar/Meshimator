#pragma once

#include <iostream>
#include <cstdint>

namespace Utils
{
    class Vertex;

    //Triangle struct mainly used as indexes for meshes
    struct Triangle
    {
        Triangle()
            : a(0)
            , b(0)
            , c(0)
            , deleted(false)
        {}

        Triangle(uint32_t a_, uint32_t b_, uint32_t c_)
            : a(a_)
            , b(b_)
            , c(c_)
            , deleted(false)
        {}

        bool Remove(Utils::Vertex* new_v, Utils::Vertex* v);

        Triangle  operator+(uint32_t u)
        {
            return Triangle{a + u, b + u, c + u};
        }

        Triangle& operator+=(uint32_t u)
        {
            a += u;
            b += u;
            c += u;
            return *this;
        }

        uint32_t a;
        uint32_t b;
        uint32_t c;
        bool     deleted;

        friend std::ostream& operator<<(std::ostream& o, const Triangle& t);
    };
}
