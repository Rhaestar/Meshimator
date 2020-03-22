#include "vertex.hh"
#include <algorithm>

namespace Utils
{
    void Vertex::FillQ(std::vector<Vertex>& vertices)
    {
        for (Triangle* t: trefs_)
        {
            Vector4 ab = vertices[t->b].GetPos() - vertices[t->a].GetPos();
            Vector4 ac = vertices[t->c].GetPos() - vertices[t->a].GetPos();
            Vector4 n = ab ^ ac;

            float a = n.x;
            float b = n.y;
            float c = n.z;

            float d = -a * pos_.x - b * pos_.y - c * pos_.z;
            SymMat K(a, b, c, d);
            std::cout << a << " " << b << " " << c << " " << d << "\n";
            std::cout << vertices[t->a].GetPos() << "\n";
            std::cout << vertices[t->b].GetPos() << "\n";
            std::cout << vertices[t->c].GetPos() << "\n";
            Q_ += K;
        }
    }

    void Vertex::AddTriangle(Triangle* ref)
    {
        if (std::find(trefs_.begin(), trefs_.end(), ref) == trefs_.end())
            trefs_.push_back(ref);
    }

    std::ostream& operator<<(std::ostream& out, const Vertex& v)
    {
        out << v.pos_ << "\n";
        return out << v.Q_;
    }
}
