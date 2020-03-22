#include "symmat.hh"

namespace Utils
{
    std::ostream& operator<<(std::ostream& o, const SymMat& m)
    {
        o << m.mat_[0] << " " << m.mat_[1] << " " << m.mat_[3] << " " << m.mat_[4] << "\n";
        o << m.mat_[1] << " " << m.mat_[4] << " " << m.mat_[5] << " " << m.mat_[6] << "\n";
        o << m.mat_[2] << " " << m.mat_[5] << " " << m.mat_[7] << " " << m.mat_[8] << "\n";
        o << m.mat_[3] << " " << m.mat_[6] << " " << m.mat_[8] << " " << m.mat_[9] << "\n";
        return o;
    }
}
