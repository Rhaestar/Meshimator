#pragma once

#include "vertex.hh"
#include "triangle.hh"
#include "heap.hh"
#include "vertexpair.hh"
#include <vector>

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes, size_t target);

void UpdateTriangles(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes);

Utils::VertexPair* MakePair(Utils::Vertex& v1, Utils::Vertex& v2);

void CreatePair(std::vector<Utils::Vertex>& vertices,
        Utils::Triangle& index, Utils::Heap& pairs);

size_t ContractPair(Utils::Heap& h);
