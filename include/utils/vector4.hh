#pragma once

#include <iostream>

namespace Utils
{
    struct Vector4
    {
        Vector4();
        Vector4(float x, float y, float z);
        Vector4(const Vector4& v);
        Vector4& operator=(const Vector4&) = default;

        Vector4                 operator+(float f) const;
        Vector4                 operator+(const Vector4& v) const;
        Vector4&                operator+=(float f);
        Vector4&                operator+=(const Vector4& v);

        Vector4                 operator-(float f) const;
        Vector4                 operator-(const Vector4& v) const;
        Vector4&                operator-=(float f);
        Vector4&                operator-=(const Vector4& v);

        Vector4                 operator*(float f) const;
        Vector4                 operator*(const Vector4& v) const;
        Vector4&                operator*=(float f);
        Vector4&                operator*=(const Vector4& v);

        Vector4                 operator/(float f) const;
        Vector4                 operator/(const Vector4& v) const;
        Vector4&                operator/=(float f);
        Vector4&                operator/=(const Vector4& v);

        Vector4                 operator^(const Vector4& v) const; //Cross Product

        bool                    operator==(const Vector4& v) const;
        bool                    operator!=(const Vector4& v) const;

        float                   norm() const;
        Vector4&                normalize();
        Vector4                 normalized() const;

        float                   Dist(const Vector4& v) const;
        float                   SquareDist(const Vector4& v) const;

        float                   dot(const Vector4& v) const;
        Vector4                 cross(const Vector4& v) const;

        Vector4                 Reflect(const Vector4& normal) const;

        friend std::ostream&    operator<<(std::ostream& os, const Vector4& v);

        float x;
        float y;
        float z;
        float h;
    };
}

#include "vector4.hxx"
