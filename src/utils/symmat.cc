#include "symmat.hh"
#include <iomanip>

namespace Utils
{
    std::ostream& operator<<(std::ostream& o, const SymMat& m)
    {
        o << std::setw(5) << m.mat_[0]
            << std::setw(5) << m.mat_[1]
            << std::setw(5) << m.mat_[3]
            << std::setw(5) << m.mat_[4] << "\n";
        o << std::setw(5) << m.mat_[1]
            << std::setw(5) << m.mat_[4]
            << std::setw(5) << m.mat_[5]
            << std::setw(5) << m.mat_[6] << "\n";
        o << std::setw(5) << m.mat_[2]
            << std::setw(5) << m.mat_[5]
            << std::setw(5) << m.mat_[7]
            << std::setw(5) << m.mat_[8] << "\n";
        o << std::setw(5) << m.mat_[3]
            << std::setw(5) << m.mat_[6]
            << std::setw(5) << m.mat_[8]
            << std::setw(5) << m.mat_[9] << "\n";
        return o;
    }
}
