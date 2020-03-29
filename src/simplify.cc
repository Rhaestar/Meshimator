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

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes, size_t /*target*/)
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
    //TODO Main Loop

}
