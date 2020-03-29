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
                VertexPair* temp = vect[index];
                vect[index] = vect[indexup];
                vect[indexup] = temp;
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
        while (index * 2 < size)
        {
            float cost = vect[index]->GetCost();
            float costup1 = vect[index * 2]->GetCost();
            if (costup1 < cost)
            {
                VertexPair* temp = vect[index];
                vect[index] = vect[index * 2];
                vect[index * 2] = temp;
                index = index * 2;
            }
            else if (index * 2 + 1 < size)
            {
                float costup2 = vect[index * 2 + 1]->GetCost();
                if (costup2 < cost)
                {
                    VertexPair* temp = vect[index];
                    vect[index] = vect[index * 2 + 1];
                    vect[index * 2 + 1] = temp;
                    index = index * 2 + 1;
                }
                else
                    break;
            }
            else
                break;
        }
        return index;
    }
}
