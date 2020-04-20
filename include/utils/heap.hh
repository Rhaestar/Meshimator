#pragma once

#include "vertexpair.hh"
#include <vector>

namespace Utils
{
    struct Heap
    {
        Heap() {}
        ~Heap();

        void Insert(VertexPair* vp);
        VertexPair* Pop(size_t i);
        void Update(size_t index);
        void Heapify();
        void Print();

        std::vector<VertexPair*> vect;
    private:
        size_t UpdateUp(size_t index);
        size_t UpdateDown(size_t index);
    };
}
