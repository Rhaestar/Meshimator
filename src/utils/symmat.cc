#include "symmat.hh"
#include <iomanip>

namespace Utils
{
    std::ostream& operator<<(std::ostream& o, const SymMat& m)
    {
        o << std::setw(10) << m.mat_[ 0 ]
            << std::setw(10) << m.mat_[ 1 ]
            << std::setw(10) << m.mat_[ 2 ]
            << std::setw(10) << m.mat_[ 3 ] << "\n";
        o << std::setw(10) << m.mat_[ 1 ]
            << std::setw(10) << m.mat_[ 4 ]
            << std::setw(10) << m.mat_[ 5 ]
            << std::setw(10) << m.mat_[ 6 ] << "\n";
        o << std::setw(10) << m.mat_[ 2 ]
            << std::setw(10) << m.mat_[ 5 ]
            << std::setw(10) << m.mat_[ 7 ]
            << std::setw(10) << m.mat_[ 8 ] << "\n";
        o << std::setw(10) << m.mat_[ 3 ]
            << std::setw(10) << m.mat_[ 6 ]
            << std::setw(10) << m.mat_[ 8 ]
            << std::setw(10) << m.mat_[ 9 ] << "\n";
        return o;
    }

    bool SymMat::GetInverse(float inv[16])
    {
        float temp[16];
        temp[0] = mat_[0]; temp[1] = mat_[1]; temp[2] = mat_[2]; temp[3] = mat_[3];
        temp[4] = mat_[1]; temp[5] = mat_[4]; temp[6] = mat_[5]; temp[7] = mat_[6];
        temp[8] = mat_[2]; temp[9] = mat_[5]; temp[10] = mat_[7]; temp[11] = mat_[8];
        temp[12] = 0.f; temp[13] = 0.f; temp[14] = 0.f; temp[15] = 1.f;


        inv[0] = temp[5]  * temp[10] * temp[15] -
            temp[5]  * temp[11] * temp[14] -
            temp[9]  * temp[6]  * temp[15] +
            temp[9]  * temp[7]  * temp[14] +
            temp[13] * temp[6]  * temp[11] -
            temp[13] * temp[7]  * temp[10];

        inv[4] = -temp[4]  * temp[10] * temp[15] +
            temp[4]  * temp[11] * temp[14] +
            temp[8]  * temp[6]  * temp[15] -
            temp[8]  * temp[7]  * temp[14] -
            temp[12] * temp[6]  * temp[11] +
            temp[12] * temp[7]  * temp[10];

        inv[8] = temp[4]  * temp[9] * temp[15] -
            temp[4]  * temp[11] * temp[13] -
            temp[8]  * temp[5] * temp[15] +
            temp[8]  * temp[7] * temp[13] +
            temp[12] * temp[5] * temp[11] -
            temp[12] * temp[7] * temp[9];

        inv[12] = -temp[4]  * temp[9] * temp[14] +
            temp[4]  * temp[10] * temp[13] +
            temp[8]  * temp[5] * temp[14] -
            temp[8]  * temp[6] * temp[13] -
            temp[12] * temp[5] * temp[10] +
            temp[12] * temp[6] * temp[9];

        inv[1] = -temp[1]  * temp[10] * temp[15] +
            temp[1]  * temp[11] * temp[14] +
            temp[9]  * temp[2] * temp[15] -
            temp[9]  * temp[3] * temp[14] -
            temp[13] * temp[2] * temp[11] +
            temp[13] * temp[3] * temp[10];

        inv[5] = temp[0]  * temp[10] * temp[15] -
            temp[0]  * temp[11] * temp[14] -
            temp[8]  * temp[2] * temp[15] +
            temp[8]  * temp[3] * temp[14] +
            temp[12] * temp[2] * temp[11] -
            temp[12] * temp[3] * temp[10];

        inv[9] = -temp[0]  * temp[9] * temp[15] +
            temp[0]  * temp[11] * temp[13] +
            temp[8]  * temp[1] * temp[15] -
            temp[8]  * temp[3] * temp[13] -
            temp[12] * temp[1] * temp[11] +
            temp[12] * temp[3] * temp[9];

        inv[13] = temp[0]  * temp[9] * temp[14] -
            temp[0]  * temp[10] * temp[13] -
            temp[8]  * temp[1] * temp[14] +
            temp[8]  * temp[2] * temp[13] +
            temp[12] * temp[1] * temp[10] -
            temp[12] * temp[2] * temp[9];

        inv[2] = temp[1]  * temp[6] * temp[15] -
            temp[1]  * temp[7] * temp[14] -
            temp[5]  * temp[2] * temp[15] +
            temp[5]  * temp[3] * temp[14] +
            temp[13] * temp[2] * temp[7] -
            temp[13] * temp[3] * temp[6];

        inv[6] = -temp[0]  * temp[6] * temp[15] +
            temp[0]  * temp[7] * temp[14] +
            temp[4]  * temp[2] * temp[15] -
            temp[4]  * temp[3] * temp[14] -
            temp[12] * temp[2] * temp[7] +
            temp[12] * temp[3] * temp[6];

        inv[10] = temp[0]  * temp[5] * temp[15] -
            temp[0]  * temp[7] * temp[13] -
            temp[4]  * temp[1] * temp[15] +
            temp[4]  * temp[3] * temp[13] +
            temp[12] * temp[1] * temp[7] -
            temp[12] * temp[3] * temp[5];

        inv[14] = -temp[0]  * temp[5] * temp[14] +
            temp[0]  * temp[6] * temp[13] +
            temp[4]  * temp[1] * temp[14] -
            temp[4]  * temp[2] * temp[13] -
            temp[12] * temp[1] * temp[6] +
            temp[12] * temp[2] * temp[5];

        inv[3] = -temp[1] * temp[6] * temp[11] +
            temp[1] * temp[7] * temp[10] +
            temp[5] * temp[2] * temp[11] -
            temp[5] * temp[3] * temp[10] -
            temp[9] * temp[2] * temp[7] +
            temp[9] * temp[3] * temp[6];

        inv[7] = temp[0] * temp[6] * temp[11] -
            temp[0] * temp[7] * temp[10] -
            temp[4] * temp[2] * temp[11] +
            temp[4] * temp[3] * temp[10] +
            temp[8] * temp[2] * temp[7] -
            temp[8] * temp[3] * temp[6];

        inv[11] = -temp[0] * temp[5] * temp[11] +
            temp[0] * temp[7] * temp[9] +
            temp[4] * temp[1] * temp[11] -
            temp[4] * temp[3] * temp[9] -
            temp[8] * temp[1] * temp[7] +
            temp[8] * temp[3] * temp[5];

        inv[15] = temp[0] * temp[5] * temp[10] -
            temp[0] * temp[6] * temp[9] -
            temp[4] * temp[1] * temp[10] +
            temp[4] * temp[2] * temp[9] +
            temp[8] * temp[1] * temp[6] -
            temp[8] * temp[2] * temp[5];

        float det = temp[0] * inv[0] + temp[1] * inv[4] + temp[2] * inv[8] + temp[3] * inv[12];

        if (fabsf(det) < 0.0001)
        {
            return false;
        }

        det = 1.f / det;
        for (int i = 0; i < 16; ++i)
        {
            inv[i] = inv[i] * det;
        }

        return true;

    }
}
