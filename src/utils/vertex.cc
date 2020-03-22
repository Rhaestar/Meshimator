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

            float d = -a - b - c;
            SymMat K(a, b, c, d);
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
