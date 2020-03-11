#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.hh"

#include "vector4.hh"
#include "triangle.hh"
#include <iostream>
#include <vector>


//TODO Proper parser
void parse_obj(char* file, std::vector<Utils::Vector4>& vertices,
        std::vector<Utils::Triangle>& indexes)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warn;
    std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, file);


    if (!warn.empty()) {
        std::cerr << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << err << std::endl;
    }

    if (!ret) {
        exit(1);
    }

    //TODO: assuming 1 shape for now
    for (size_t s = 0; s < shapes.size(); s++)
    {
        size_t index_offset = 0;
        for (size_t f = 0, fEnd = shapes[s].mesh.num_face_vertices.size(); f < fEnd; f++)
        {
            size_t fv = shapes[s].mesh.num_face_vertices[f];
            //We assume that we have only triangles
            for (size_t v = 0; v < fv; v++) {
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
                tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
                tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];

                Utils::Vector4  vertex{vx, vy, vz};
                vertices.push_back(vertex);
            }

            uint32_t idx = vertices.size();

            Utils::Triangle triangle{idx - 1, idx - 2, idx - 3};
            indexes.push_back(triangle);

            index_offset += fv;
        }
    }
}

int main(int argc, char* argv[])
{
    //TODO: Add Positional arguments to define target
    if (argc != 3)
    {
        std::cerr << "USAGE: ./meshimator input_file output_file\n";
        return 1;
    }

    std::vector<Utils::Vector4> vertices;
    std::vector<Utils::Triangle> indexes;
    parse_obj(argv[1], vertices, indexes);
    for (size_t i = 0; i < indexes.size(); ++i)
    {
        std::cout << vertices[indexes[i].a]
                  << vertices[indexes[i].b] << vertices[indexes[i].c] << "\n";
    }
    return 0;
}
