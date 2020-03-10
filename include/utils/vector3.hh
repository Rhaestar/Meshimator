#pragma once

#include <iostream>

namespace Utils
{
    struct Vector3
    {
        Vector3();
        Vector3(float x, float y, float z);
        Vector3(const Vector3& v);
        Vector3& operator=(const Vector3&) = default;

        Vector3                 operator+(float f) const;
        Vector3                 operator+(const Vector3& v) const;
        Vector3&                operator+=(float f);
        Vector3&                operator+=(const Vector3& v);

        Vector3                 operator-(float f) const;
        Vector3                 operator-(const Vector3& v) const;
        Vector3&                operator-=(float f);
        Vector3&                operator-=(const Vector3& v);

        Vector3                 operator*(float f) const;
        Vector3                 operator*(const Vector3& v) const;
        Vector3&                operator*=(float f);
        Vector3&                operator*=(const Vector3& v);

        Vector3                 operator/(float f) const;
        Vector3                 operator/(const Vector3& v) const;
        Vector3&                operator/=(float f);
        Vector3&                operator/=(const Vector3& v);

        Vector3                 operator^(const Vector3& v) const; //Cross Product

        bool                    operator==(const Vector3& v) const;
        bool                    operator!=(const Vector3& v) const;

        float                   norm() const;
        Vector3&                normalize();
        Vector3                 normalized() const;

        float                   Dist(const Vector3& v) const;
        float                   SquareDist(const Vector3& v) const;

        float                   dot(const Vector3& v) const;
        Vector3                 cross(const Vector3& v) const;

        Vector3                 Reflect(const Vector3& normal) const;

        friend std::ostream&    operator<<(std::ostream& os, const Vector3& v);

        float x;
        float y;
        float z;
    };
}

#include "vector3.hxx"
