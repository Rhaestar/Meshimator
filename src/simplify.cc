#include "simplify.hh"

#include <iostream>
#include <algorithm>
#include <set>

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

bool cmp(Utils::VertexPair* lhs, Utils::VertexPair* rhs)
{
    return lhs->GetCost() < rhs->GetCost();
}

size_t ContractPair(Utils::Heap& h)

{
    std::cout << "Start Contract \n";
    auto it = std::min_element(h.vect.begin(), h.vect.end(), cmp);
    Utils::VertexPair* vp = *it;
    h.vect.erase(it);

    for (size_t i = 0; i < h.vect.size(); i++)
    {
        auto p = h.vect[i];
        if (p->GetCost() < vp->GetCost())
            std::cout << "ERROR\n" << p->GetFirst()->GetIndex() << " " << p->GetSecond()->GetIndex() << "\n" << "Cost " << p->GetCost() << " vs " << vp->GetCost() << "\n";
    }

    std::cout << vp->GetCost() << "\n";
    Utils::Vertex* v1 = vp->GetFirst();
    Utils::Vertex* v2 = vp->GetSecond();
    std::cout << *v1 << "\n";
    std::cout << *v2 << "\n";

    if (v1->IsDeleted() || v2->IsDeleted())
    {
        std::cout << "AZE\n";
    }

    v1->SetPos(vp->GetOptimalVertex());
    size_t deleted_triangles = v2->ReplaceBy(v1);

    for (size_t i = 0; i < h.vect.size(); ++i)
    {
        auto p = h.vect[i];
        if(p->Replace(v1, v2) && p->GetFirst() == p->GetSecond())
        {
            h.vect.erase(h.vect.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < h.vect.size(); ++i)
    {
        auto p = h.vect[i];
        if (p->GetFirst()->GetIndex() == v1->GetIndex() && p->GetFirst() != v1)
            std::cout << "ERROR\n";
        if (p->GetSecond()->GetIndex() == v1->GetIndex() && p->GetSecond() != v1)
            std::cout << "ERROR\n";
    }

    std::set<Utils::VertexPair*> s( h.vect.begin(), h.vect.end() );
    h.vect.assign( s.begin(), s.end() );

//    delete vp;

    return deleted_triangles;
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
        std::cout << "simplified " << deleted << "\n";
        curr_count -= deleted;
    }
}
