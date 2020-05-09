#include "symmat.hh"
#include <iomanip>

#define INV(i,j) (temp[ i * 4 + j ])

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

        float det =
            INV(0,3)*INV(1,2)*INV(2,1)*INV(3,0) - INV(0,2)*INV(1,3)*INV(2,1)*INV(3,0) -
            INV(0,3)*INV(1,1)*INV(2,2)*INV(3,0) + INV(0,1)*INV(1,3)*INV(2,2)*INV(3,0) +
            INV(0,2)*INV(1,1)*INV(2,3)*INV(3,0) - INV(0,1)*INV(1,2)*INV(2,3)*INV(3,0) - 
            INV(0,3)*INV(1,2)*INV(2,0)*INV(3,1) + INV(0,2)*INV(1,3)*INV(2,0)*INV(3,1) +
            INV(0,3)*INV(1,0)*INV(2,2)*INV(3,1) - INV(0,0)*INV(1,3)*INV(2,2)*INV(3,1) -
            INV(0,2)*INV(1,0)*INV(2,3)*INV(3,1) + INV(0,0)*INV(1,2)*INV(2,3)*INV(3,1) +
            INV(0,3)*INV(1,1)*INV(2,0)*INV(3,2) - INV(0,1)*INV(1,3)*INV(2,0)*INV(3,2) -
            INV(0,3)*INV(1,0)*INV(2,1)*INV(3,2) + INV(0,0)*INV(1,3)*INV(2,1)*INV(3,2) +
            INV(0,1)*INV(1,0)*INV(2,3)*INV(3,2) - INV(0,0)*INV(1,1)*INV(2,3)*INV(3,2) -
            INV(0,2)*INV(1,1)*INV(2,0)*INV(3,3) + INV(0,1)*INV(1,2)*INV(2,0)*INV(3,3) +
            INV(0,2)*INV(1,0)*INV(2,1)*INV(3,3) - INV(0,0)*INV(1,2)*INV(2,1)*INV(3,3) - 
            INV(0,1)*INV(1,0)*INV(2,2)*INV(3,3) + INV(0,0)*INV(1,1)*INV(2,2)*INV(3,3);

        std::cout << det << "\n";

        if (fabsf(det) < 0.0001)
        {
            return false;
        }


        inv[0]  = INV(1,2)*INV(2,3)*INV(3,1) - INV(1,3)*INV(2,2)*INV(3,1) +
                  INV(1,3)*INV(2,1)*INV(3,2) - INV(1,1)*INV(2,3)*INV(3,2) -
                  INV(1,2)*INV(2,1)*INV(3,3) + INV(1,1)*INV(2,2)*INV(3,3);
        inv[1]  = INV(0,3)*INV(2,2)*INV(3,1) - INV(0,2)*INV(2,3)*INV(3,1) -
                  INV(0,3)*INV(2,1)*INV(3,2) + INV(0,1)*INV(2,3)*INV(3,2) +
                  INV(0,2)*INV(2,1)*INV(3,3) - INV(0,1)*INV(2,2)*INV(3,3);
        inv[2]  = INV(0,2)*INV(1,3)*INV(3,1) - INV(0,3)*INV(1,2)*INV(3,1) +
                  INV(0,3)*INV(1,1)*INV(3,2) - INV(0,1)*INV(1,3)*INV(3,2) -
                  INV(0,2)*INV(1,1)*INV(3,3) + INV(0,1)*INV(1,2)*INV(3,3);
        inv[3]  = INV(0,3)*INV(1,2)*INV(2,1) - INV(0,2)*INV(1,3)*INV(2,1) -
                  INV(0,3)*INV(1,1)*INV(2,2) + INV(0,1)*INV(1,3)*INV(2,2) +
                  INV(0,2)*INV(1,1)*INV(2,3) - INV(0,1)*INV(1,2)*INV(2,3);
        inv[4]  = INV(1,3)*INV(2,2)*INV(3,0) - INV(1,2)*INV(2,3)*INV(3,0) -
                  INV(1,3)*INV(2,0)*INV(3,2) + INV(1,0)*INV(2,3)*INV(3,2) +
                  INV(1,2)*INV(2,0)*INV(3,3) - INV(1,0)*INV(2,2)*INV(3,3);
        inv[5]  = INV(0,2)*INV(2,3)*INV(3,0) - INV(0,3)*INV(2,2)*INV(3,0) +
                  INV(0,3)*INV(2,0)*INV(3,2) - INV(0,0)*INV(2,3)*INV(3,2) -
                  INV(0,2)*INV(2,0)*INV(3,3) + INV(0,0)*INV(2,2)*INV(3,3);
        inv[6]  = INV(0,3)*INV(1,2)*INV(3,0) - INV(0,2)*INV(1,3)*INV(3,0) -
                  INV(0,3)*INV(1,0)*INV(3,2) + INV(0,0)*INV(1,3)*INV(3,2) +
                  INV(0,2)*INV(1,0)*INV(3,3) - INV(0,0)*INV(1,2)*INV(3,3);
        inv[7]  = INV(0,2)*INV(1,3)*INV(2,0) - INV(0,3)*INV(1,2)*INV(2,0) +
                  INV(0,3)*INV(1,0)*INV(2,2) - INV(0,0)*INV(1,3)*INV(2,2) -
                  INV(0,2)*INV(1,0)*INV(2,3) + INV(0,0)*INV(1,2)*INV(2,3);
        inv[8]  = INV(1,1)*INV(2,3)*INV(3,0) - INV(1,3)*INV(2,1)*INV(3,0) +
                  INV(1,3)*INV(2,0)*INV(3,1) - INV(1,0)*INV(2,3)*INV(3,1) -
                  INV(1,1)*INV(2,0)*INV(3,3) + INV(1,0)*INV(2,1)*INV(3,3);
        inv[9]  = INV(0,3)*INV(2,1)*INV(3,0) - INV(0,1)*INV(2,3)*INV(3,0) -
                  INV(0,3)*INV(2,0)*INV(3,1) + INV(0,0)*INV(2,3)*INV(3,1) + 
                  INV(0,1)*INV(2,0)*INV(3,3) - INV(0,0)*INV(2,1)*INV(3,3);
        inv[10] = INV(0,1)*INV(1,3)*INV(3,0) - INV(0,3)*INV(1,1)*INV(3,0) +
                  INV(0,3)*INV(1,0)*INV(3,1) - INV(0,0)*INV(1,3)*INV(3,1) -
                  INV(0,1)*INV(1,0)*INV(3,3) + INV(0,0)*INV(1,1)*INV(3,3);
        inv[11] = INV(0,3)*INV(1,1)*INV(2,0) - INV(0,1)*INV(1,3)*INV(2,0) -
                  INV(0,3)*INV(1,0)*INV(2,1) + INV(0,0)*INV(1,3)*INV(2,1) +
                  INV(0,1)*INV(1,0)*INV(2,3) - INV(0,0)*INV(1,1)*INV(2,3);
        inv[12] = INV(1,2)*INV(2,1)*INV(3,0) - INV(1,1)*INV(2,2)*INV(3,0) -
                  INV(1,2)*INV(2,0)*INV(3,1) + INV(1,0)*INV(2,2)*INV(3,1) +
                  INV(1,1)*INV(2,0)*INV(3,2) - INV(1,0)*INV(2,1)*INV(3,2);
        inv[13] = INV(0,1)*INV(2,2)*INV(3,0) - INV(0,2)*INV(2,1)*INV(3,0) +
                  INV(0,2)*INV(2,0)*INV(3,1) - INV(0,0)*INV(2,2)*INV(3,1) -
                  INV(0,1)*INV(2,0)*INV(3,2) + INV(0,0)*INV(2,1)*INV(3,2);
        inv[14] = INV(0,2)*INV(1,1)*INV(3,0) - INV(0,1)*INV(1,2)*INV(3,0) -
                  INV(0,2)*INV(1,0)*INV(3,1) + INV(0,0)*INV(1,2)*INV(3,1) +
                  INV(0,1)*INV(1,0)*INV(3,2) - INV(0,0)*INV(1,1)*INV(3,2);
        inv[15] = INV(0,1)*INV(1,2)*INV(2,0) - INV(0,2)*INV(1,1)*INV(2,0) +
                  INV(0,2)*INV(1,0)*INV(2,1) - INV(0,0)*INV(1,2)*INV(2,1) -
                  INV(0,1)*INV(1,0)*INV(2,2) + INV(0,0)*INV(1,1)*INV(2,2);

        det = 1.f / det;
        for (int i = 0; i < 16; ++i)
        {
            inv[i] = inv[i] * det;
            std::cout << inv[i] << "\n";
        }

        return true;

    }
}
