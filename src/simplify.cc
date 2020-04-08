#include "simplify.hh"

#include <iostream>

Utils::VertexPair* MakePair(Utils::Vertex& v1, Utils::Vertex& v2)
{
    if (!v1.CheckPair(v2))
    {
        Utils::VertexPair* vp = new Utils::VertexPair(&v1, &v2);
        v1.AddPair(vp);
        v2.AddPair(vp);
        return vp;
    }
    return nullptr;
}

void CreatePair(std::vector<Utils::Vertex>& vertices,
        Utils::Triangle& index, Utils::Heap& pairs)
{
    Utils::Vertex& a = vertices[index.a];
    Utils::Vertex& b = vertices[index.b];
    Utils::Vertex& c = vertices[index.c];

    Utils::VertexPair* ab = MakePair(a, b);
    Utils::VertexPair* ac = MakePair(a, c);
    Utils::VertexPair* bc = MakePair(b, c);

    if (ab != nullptr)
        pairs.Insert(ab);
    if (ac != nullptr)
        pairs.Insert(ac);
    if (bc != nullptr)
        pairs.Insert(bc);

}

void ContractPair(std::vector<Utils::Triangle>& indexes, Utils::Heap& h)
{
    Utils::VertexPair* vp = h.Pop();
    Utils::Vertex* v1 = vp->GetFirst();
    Utils::Vertex* v2 = vp->GetSecond();

    for (Utils::Triangle& t : indexes)
    {
        t.Remove(v1, v2); 
    }

    for (size_t i = 0; i < h.vect.size(); i++)
    {
        auto p = h.vect[i];
        
        if (p->Replace(v1, v2))
            h.Update(i);
    }

    delete vp;
    v2->Delete();
}

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes, size_t target)
{
    for (Utils::Vertex& v : vertices)
        v.FillQ(vertices);

    Utils::Heap h;

    for (Utils::Triangle& index : indexes)
        CreatePair(vertices, index, h);

    for (auto vp : h.vect)
    {
        std::cout << *(vp->GetFirst()) << "\n" << *(vp->GetSecond()) << "\na\n";
    }

    size_t del_count = 0;
    while (indexes.size() - del_count > target) {
        ContractPair(indexes, h);

        del_count = 0;
        for (auto i = indexes.begin(); i < indexes.end(); i++)
        {
            if ((*i).deleted)
                del_count++;
        }
    }
}
