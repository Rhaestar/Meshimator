#include "vertex.hh"
#include <algorithm>

namespace Utils
{
    size_t Vertex::ReplaceBy(Vertex* v, std::vector<VertexPair*>& toDelete)
    {
        toDelete.clear();
        deleted_ = true;
        size_t deleted_triangles = 0;

        for (auto pt : trefs_)
        {
            if (pt->deleted)
                continue;
            if (pt->Remove(v, this))
                deleted_triangles++;
            else
                v->AddTriangle(pt);
        }
        v->Q_ += Q_;

        for (auto pp : prefs_)
        {
            pp->SetInvalid();
            Vertex* v2 = pp->GetFirst() == this ? pp->GetSecond() : pp->GetFirst();
            if (*v2 == *v)
                toDelete.push_back(pp);
            else if (!v->CheckPair(*v2))
                v->AddPair(pp);
            else
            {
                v2->RemovePair(pp);
                toDelete.push_back(pp);
            }
        }

        return deleted_triangles;
    }

    void Vertex::FillQ(std::vector<Vertex>& vertices)
    {
        for (Triangle* t: trefs_)
        {
            Vector4 ab = vertices[t->b].GetPos() - vertices[t->a].GetPos();
            Vector4 ac = vertices[t->c].GetPos() - vertices[t->a].GetPos();
            Vector4 n = ab ^ ac;
            n.normalize();

            float a = n.x;
            float b = n.y;
            float c = n.z;

            float d = -a * pos_.x - b * pos_.y - c * pos_.z;
            SymMat K(a, b, c, d);
            Q_ += K;
        }
    }

    void Vertex::AddTriangle(Triangle* ref)
    {
        if (std::find(trefs_.begin(), trefs_.end(), ref) == trefs_.end())
            trefs_.push_back(ref);
    }

    void Vertex::AddPair(VertexPair* ref)
    {
        prefs_.push_back(ref);
    }

    void Vertex::RemovePair(VertexPair* ref)
    {
        auto it = std::find(prefs_.begin(), prefs_.end(), ref);
        if (it != prefs_.end())
        {
            prefs_.erase(it);
        }
    }

    std::ostream& operator<<(std::ostream& out, const Vertex& v)
    {
        out << "index " << v.index_ << "\n";
        out << v.pos_ << "\n";
        return out;
    }

    bool Vertex::CheckPair(const Vertex& v)
    {
        for (auto vp : prefs_)
            if (*(vp->GetFirst()) == v || *(vp->GetSecond()) == v)
                return true;
        return false;
    }
}
