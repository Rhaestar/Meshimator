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

    for (size_t i = 0; i < attrib.vertices.size(); i += 3)
    {
        Utils::Vector4 v;
        v.x = attrib.vertices[i + 0];
        v.y = attrib.vertices[i + 1];
        v.z = attrib.vertices[i + 2];
        vertices.push_back(v);
    }

    //TODO: assuming 1 shape for now
    for (size_t s = 0; s < shapes.size(); s++)
    {
        size_t index_offset = 0;
        for (size_t f = 0, fEnd = shapes[s].mesh.num_face_vertices.size(); f < fEnd; f++)
        {
            size_t fv = shapes[s].mesh.num_face_vertices[f];
            //We assume that we have only triangles
            Utils::Triangle t;

            t.a = shapes[s].mesh.indices[index_offset + 0].vertex_index;
            t.b = shapes[s].mesh.indices[index_offset + 1].vertex_index;
            t.c = shapes[s].mesh.indices[index_offset + 2].vertex_index;
            indexes.push_back(t);

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
