#include "simplify.hh"

#include <iostream>
#include <algorithm>
#include <unordered_map>

Utils::VertexPair* MakePair(Utils::Vertex* v1, Utils::Vertex* v2)
{
    if (!v1->CheckPair(*v2))
    {
        Utils::VertexPair* vp = new Utils::VertexPair(v1, v2);
        v1->AddPair(vp);
        v2->AddPair(vp);
        return vp;
    }
    return nullptr;
}

void CreatePair(std::vector<Utils::Vertex>& vertices,
        Utils::Triangle& index, Utils::Heap& pairs)
{
    Utils::Vertex* a = &vertices[index.a];
    Utils::Vertex* b = &vertices[index.b];
    Utils::Vertex* c = &vertices[index.c];

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

size_t ContractPair(Utils::Heap& h)
{
    auto it = h.Pop(0);
    Utils::VertexPair* vp = it;

    Utils::Vertex* v1 = vp->GetFirst();
    Utils::Vertex* v2 = vp->GetSecond();

    v1->SetPos(vp->GetOptimalVertex());

    std::vector<Utils::VertexPair*> toDelete;
    size_t deleted_triangles = v2->ReplaceBy(v1, toDelete);

    v1->RemovePair(vp);

    for (size_t i = 0; i < h.vect.size(); ++i)
    {
        Utils::VertexPair* p = h.vect[i];
        if (std::find(toDelete.begin(), toDelete.end(), p) != toDelete.end())
        {
            h.vect.erase(h.vect.begin() + i--);
            delete p;
        }
        else
            p->Replace(v1, v2);
    }

    h.Heapify();

    delete vp;

    return deleted_triangles;
}

void UpdateTriangles(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes)
{
    std::unordered_map<size_t, size_t> map;
    size_t new_i = 0;
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        if (vertices[i].IsDeleted())
            continue;

        map.insert(std::pair<size_t, size_t>(i, new_i++));
    }

    for (Utils::Triangle& t : indexes)
    {
        t.a = map[t.a];
        t.b = map[t.b];
        t.c = map[t.c];
    }
}

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes, size_t target)
{
    for (Utils::Vertex& v : vertices)
        v.FillQ(vertices);

    Utils::Heap h;

    for (Utils::Triangle& index : indexes)
        CreatePair(vertices, index, h);

    size_t curr_count = indexes.size();
    std::cout << curr_count << " " << target << "\n";
    while (curr_count > target) {
        size_t deleted = ContractPair(h);
        curr_count -= deleted;
    }

    UpdateTriangles(vertices, indexes);
}
