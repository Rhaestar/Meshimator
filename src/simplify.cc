#include "simplify.hh"

void simplify(std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& /*indexes*/, size_t /*target*/)
{
    for (Utils::Vertex& v : vertices)
        v.FillQ(vertices);
}
