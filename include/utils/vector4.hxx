#include <cmath>
#include <iostream>

namespace Utils
{
    inline Vector4::Vector4()
        : x(0.f)
        , y(0.f)
        , z(0.f)
        , h(1.f)
    {}

    inline Vector4::Vector4(float _x, float _y, float _z)
        : x(_x)
        , y(_y)
        , z(_z)
        , h(1.f)
    {}

    inline Vector4::Vector4(const Vector4& _v)
        : x(_v.x)
        , y(_v.y)
        , z(_v.z)
        , h(_v.h)
    {}

    inline Vector4 Vector4::operator+(float f) const
    {
        return Vector4(x + f, y + f, z + f);
    }

    inline Vector4 Vector4::operator+(const Vector4& v) const
    {
        return Vector4(x + v.x, y + v.y, z + v.z);
    }

    inline Vector4& Vector4::operator+=(float f)
    {
        x += f;
        y += f;
        z += f;
        return *this;
    }

    inline Vector4& Vector4::operator+=(const Vector4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    inline Vector4 Vector4::operator-(float f) const
    {
        return Vector4(x - f, y - f, z - f);
    }

    inline Vector4 Vector4::operator-(const Vector4& v) const
    {
        return Vector4(x - v.x, y - v.y, z - v.z);
    }

    inline Vector4& Vector4::operator-=(float f)
    {
        x -= f;
        y -= f;
        z -= f;
        return *this;
    }

    inline Vector4& Vector4::operator-=(const Vector4& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    inline Vector4 Vector4::operator*(float f) const
    {
        return Vector4(x * f, y * f, z * f);
    }

    inline Vector4 Vector4::operator*(const Vector4& v) const
    {
        return Vector4(x * v.x, y * v.y, z * v.z);
    }

    inline Vector4& Vector4::operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    inline Vector4& Vector4::operator*=(const Vector4& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    inline Vector4 Vector4::operator/(float f) const
    {
        return Vector4(x / f, y / f, z / f);
    }

    inline Vector4 Vector4::operator/(const Vector4& v) const
    {
        return Vector4(x / v.x, y / v.y, z / v.z);
    }

    inline Vector4& Vector4::operator/=(float f)
    {
        x /= f;
        y /= f;
        z /= f;
        return *this;
    }

    inline Vector4& Vector4::operator/=(const Vector4& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }

    inline Vector4 Vector4::operator^(const Vector4& v) const
    {
        float nx = y * v.z - v.y * z;
        float ny = z * v.x - v.z * x;
        float nz = x * v.y - v.x * y;
        return Vector4(nx, ny, nz);
    }

    inline bool Vector4::operator==(const Vector4& v) const
    {
        return v.x == x && v.y == y && v.z == z;
    }

    inline bool Vector4::operator!=(const Vector4& v) const
    {
        return v.x != x || v.y != y || v.z != z;
    }

    inline float Vector4::norm() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    inline Vector4& Vector4::normalize()
    {
        (*this) /= norm();
        return *this;
    }

    inline Vector4 Vector4::normalized() const
    {
        return Vector4(*this) / norm();
    }

    inline float Vector4::dot(const Vector4& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline Vector4 Vector4::cross(const Vector4& v) const
    {
        return *this ^ v;
    }

    inline float Vector4::SquareDist(const Vector4& v) const
    {
        float dx = v.x - x;
        float dy = v.y - y;
        float dz = v.z - z;
        return dx * dx + dy * dy + dz * dz;
    }

    inline float Vector4::Dist(const Vector4& v) const
    {
        return sqrtf(SquareDist(v));
    }

    inline Vector4 Vector4::Reflect(const Vector4& normal) const
    {
        return *this - normal * dot(normal) * 2.f;
    }
}
