#pragma once

#include "vertex.hh"
#include "triangle.hh"
#include <vector>

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes, size_t target);
