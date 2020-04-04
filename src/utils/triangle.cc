#include "triangle.hh"
#include "vertex.hh"

namespace Utils
{
    void Triangle::Remove(Utils::Vertex* v, Utils::Vertex* new_v)
    {
        size_t v_index = v->GetIndex();
        size_t new_index = new_v->GetIndex();

        if (v_index == a)
        {
            if (new_index == b || new_index == c)
                deleted = true;
            else
                a = new_index;
        }

        if (v_index == b)
        {
            if (new_index == a || new_index == c)
                deleted = true;
            else
                b = new_index;
        }

        if (v_index == c)
        {
            if (new_index == a || new_index == b)
                deleted = true;
            else
                c = new_v->GetIndex();
        }
    }

    std::ostream& operator <<(std::ostream& o, const Triangle& t)
    {
        //Obj files are 1-indexed;
        return o << t.a + 1 << " " << t.b + 1 << " " << t.c + 1;
    }
}
