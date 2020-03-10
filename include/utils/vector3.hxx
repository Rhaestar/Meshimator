#include <cmath>
#include <iostream>

namespace Utils
{
    inline Vector3::Vector3()
        : x(0.f)
        , y(0.f)
        , z(0.f)
    {}

    inline Vector3::Vector3(float _x, float _y, float _z)
        : x(_x)
        , y(_y)
        , z(_z)
    {}

    inline Vector3::Vector3(const Vector3& _v)
        : x(_v.x)
        , y(_v.y)
        , z(_v.z)
    {}

    inline Vector3 Vector3::operator+(float f) const
    {
        return Vector3(x + f, y + f, z + f);
    }

    inline Vector3 Vector3::operator+(const Vector3& v) const
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    inline Vector3& Vector3::operator+=(float f)
    {
        x += f;
        y += f;
        z += f;
        return *this;
    }

    inline Vector3& Vector3::operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    inline Vector3 Vector3::operator-(float f) const
    {
        return Vector3(x - f, y - f, z - f);
    }

    inline Vector3 Vector3::operator-(const Vector3& v) const
    {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    inline Vector3& Vector3::operator-=(float f)
    {
        x -= f;
        y -= f;
        z -= f;
        return *this;
    }

    inline Vector3& Vector3::operator-=(const Vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    inline Vector3 Vector3::operator*(float f) const
    {
        return Vector3(x * f, y * f, z * f);
    }

    inline Vector3 Vector3::operator*(const Vector3& v) const
    {
        return Vector3(x * v.x, y * v.y, z * v.z);
    }

    inline Vector3& Vector3::operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    inline Vector3& Vector3::operator*=(const Vector3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    inline Vector3 Vector3::operator/(float f) const
    {
        return Vector3(x / f, y / f, z / f);
    }

    inline Vector3 Vector3::operator/(const Vector3& v) const
    {
        return Vector3(x / v.x, y / v.y, z / v.z);
    }

    inline Vector3& Vector3::operator/=(float f)
    {
        x /= f;
        y /= f;
        z /= f;
        return *this;
    }

    inline Vector3& Vector3::operator/=(const Vector3& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }

    inline Vector3 Vector3::operator^(const Vector3& v) const
    {
        float nx = y * v.z - v.y * z;
        float ny = z * v.x - v.z * x;
        float nz = x * v.y - v.x * y;
        return Vector3(nx, ny, nz);
    }

    inline bool Vector3::operator==(const Vector3& v) const
    {
        return v.x == x && v.y == y && v.z == z;
    }

    inline bool Vector3::operator!=(const Vector3& v) const
    {
        return v.x != x || v.y != y || v.z != z;
    }

    inline float Vector3::norm() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    inline Vector3& Vector3::normalize()
    {
        (*this) /= norm();
        return *this;
    }

    inline Vector3 Vector3::normalized() const
    {
        return Vector3(*this) / norm();
    }

    inline float Vector3::dot(const Vector3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline Vector3 Vector3::cross(const Vector3& v) const
    {
        return *this ^ v;
    }

    inline float Vector3::SquareDist(const Vector3& v) const
    {
        float dx = v.x - x;
        float dy = v.y - y;
        float dz = v.z - z;
        return dx * dx + dy * dy + dz * dz;
    }

    inline float Vector3::Dist(const Vector3& v) const
    {
        return sqrtf(SquareDist(v));
    }

    inline Vector3 Vector3::Reflect(const Vector3& normal) const
    {
        return *this - normal * dot(normal) * 2.f;
    }
}
