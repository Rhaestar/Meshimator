#include "heap.hh"

namespace Utils
{
    Heap::~Heap()
    {
        for (auto vp : vect)
            delete vp;
    }

    void Heap::Insert(VertexPair* vp)
    {
        vect.push_back(vp);
        UpdateUp(vect.size() - 1);
    }

    VertexPair* Heap::Pop()
    {
        if (vect.size() == 0)
            return nullptr;
        VertexPair* temp = vect[0];
        vect[0] = vect[vect.size() - 1];
        vect.pop_back();
        UpdateDown(0);
        return temp;
    }

    void Heap::Update(size_t index)
    {
        UpdateDown(UpdateUp(index));
    }

    size_t Heap::UpdateUp(size_t index)
    {
        while (index > 0)
        {
            size_t indexup = (index - 1) / 2;
            float cost = vect[index]->GetCost();
            float costup = vect[indexup]->GetCost();
            if (cost < costup)
            {
                std::swap(vect[index], vect[indexup]);
                index = indexup;
            }
            else
                break;
        }
        return index;
    }

    size_t Heap::UpdateDown(size_t index)
    {
        size_t size = vect.size();
        while (index * 2 + 1 < size)
        {
            float cost = vect[index]->GetCost();
            size_t indexdown = index * 2 + 1;
            float costdown = vect[indexdown]->GetCost();
            if (indexdown + 1 < size)
            {
                float costalt = vect[indexdown + 1]->GetCost();
                if (costalt < costdown)
                {
                    indexdown += 1;
                    costdown = costalt;
                }
            }
            if (costdown < cost)
            {
                std::swap(vect[index], vect[indexdown]);
                index = indexdown;
            }
            else
                break;
        }
        return index;
    }

    void Heap::Print()
    {
        for (auto i : vect)
        {
            std::cout << "(" << i->GetFirst()->GetIndex() << ", " << i->GetSecond()->GetIndex() << ") ";
        }
        std::cout << "\n";
    }
}
