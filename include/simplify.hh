#pragma once

#include "vertex.hh"
#include "triangle.hh"
#include "heap.hh"
#include "vertexpair.hh"
#include <vector>

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes, size_t target);

Utils::VertexPair* MakePair(Utils::Vertex& v1, Utils::Vertex& v2);

void CreatePair(std::vector<Utils::Vertex>& vertices,
        Utils::Triangle& index, Utils::Heap& pairs);

void ContractPair(std::vector<Utils::Triangle>& indexes, Utils::Heap& h);

