#pragma once
#include "vector4.hh"
#include <iostream>

namespace Utils
{
    /* Half 4x4 Symmetric Matrix
     * indexes:
     * 0 1 2 3  0  1  2  3
     * 1 4 5 6  4  5  6  7
     * 2 5 7 8  8  9  10 11
     * 3 6 8 9  12 13 14 15
    */
    class SymMat
    {
        public:
            SymMat()
            {
                for (int i = 0; i < 10; ++i)
                    mat_[i] = 0;
            }

            SymMat(float a, float b, float c, float d)
            {
                mat_[0] = a * a;
                mat_[1] = a * b;
                mat_[2] = a * c;
                mat_[3] = a * d;
                mat_[4] = b * b;
                mat_[5] = b * c;
                mat_[6] = b * d;
                mat_[7] = c * c;
                mat_[8] = c * d;
                mat_[9] = d * d;
            }

            SymMat operator+(const SymMat& b) const
            {
                SymMat n;
                for (int i = 0; i < 10; ++i)
                {
                    n.mat_[i] = mat_[i] + b.mat_[i];
                }
                return n;
            }

            SymMat& operator+=(const SymMat& b)
            {
                for (int i = 0; i < 10; ++i)
                {
                    mat_[i] += b.mat_[i];
                }
                return *this;
            }

            //M * V
            Vector4 operator*(const Vector4& v) const
            {
                Vector4 res;
                res.x = mat_[0] * v.x + mat_[1] * v.y + mat_[2] * v.z + mat_[3] * v.h;
                res.y = mat_[1] * v.x + mat_[4] * v.y + mat_[5] * v.z + mat_[6] * v.h;
                res.z = mat_[2] * v.x + mat_[5] * v.y + mat_[7] * v.z + mat_[8] * v.h;
                res.h = mat_[3] * v.x + mat_[6] * v.y + mat_[8] * v.z + mat_[9] * v.h;
                return res;
            }

            //V*M
            friend Vector4 operator*(const Vector4& v, const SymMat& m)
            {
                Vector4 res;
                res.x = m.mat_[0] * v.x + m.mat_[1] * v.y + m.mat_[2] * v.z + m.mat_[3] * v.h;
                res.y = m.mat_[1] * v.x + m.mat_[4] * v.y + m.mat_[5] * v.z + m.mat_[6] * v.h;
                res.z = m.mat_[2] * v.x + m.mat_[5] * v.y + m.mat_[7] * v.z + m.mat_[8] * v.h;
                res.h = m.mat_[3] * v.x + m.mat_[6] * v.y + m.mat_[8] * v.z + m.mat_[9] * v.h;
                return res;
            }

            friend std::ostream& operator<<(std::ostream& o, const SymMat& m);

            bool GetInverse(float inv[16]);

        private:
            float mat_[10];
    };
}
