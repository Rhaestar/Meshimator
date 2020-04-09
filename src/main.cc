#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.hh"

#include "vector4.hh"
#include "triangle.hh"
#include "vertex.hh"
#include "simplify.hh"
#include <iostream>
#include <vector>


//TODO Proper parser
void parse_obj(char* file, std::vector<Utils::Vertex>& vertices,
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

    vertices.reserve(attrib.vertices.size() / 3);
    for (size_t i = 0; i < attrib.vertices.size(); i += 3)
    {
        Utils::Vector4 v;
        v.x = attrib.vertices[i + 0];
        v.y = attrib.vertices[i + 1];
        v.z = attrib.vertices[i + 2];
        v.h = 1.f;
        Utils::Vertex vertex(v, vertices.size());
        vertices.push_back(vertex);
     }

    //TODO: assuming 1 shape for now
    for (size_t s = 0; s < shapes.size(); s++)
    {
        size_t index_offset = 0;
        indexes.reserve(shapes[s].mesh.num_face_vertices.size());
        for (size_t f = 0, fEnd = shapes[s].mesh.num_face_vertices.size(); f < fEnd; f++)
        {
            size_t fv = shapes[s].mesh.num_face_vertices[f];
            //We assume that we have only triangles
            Utils::Triangle t;

            t.a = shapes[s].mesh.indices[index_offset + 0].vertex_index;
            t.b = shapes[s].mesh.indices[index_offset + 1].vertex_index;
            t.c = shapes[s].mesh.indices[index_offset + 2].vertex_index;
            indexes.push_back(t);
            Utils::Triangle& inserted = indexes[indexes.size() - 1];
            vertices[t.a].AddTriangle(&inserted);
            vertices[t.b].AddTriangle(&inserted);
            vertices[t.c].AddTriangle(&inserted);

            index_offset += fv;
        }
    }
}

void write_obj(char* file, std::vector<Utils::Vertex>& vertices,
        std::vector<Utils::Triangle>& indexes)
{
    std::ofstream out;
    out.open(file);

    out << "# " << file << "\n\n";
    out << "o shape\n\n";
    for (Utils::Vertex& v : vertices)
        out << "v " << v.GetPos() << "\n";
    out << "\n";
    for (Utils::Triangle& t : indexes)
        if (!t.deleted)
        out << "f " << t << "\n";
    out.close();
}

int main(int argc, char* argv[])
{
    //TODO: Add Positional arguments to define target
    if (argc != 4)
    {
        std::cerr << "USAGE: ./meshimator input_file output_file target\n";
        return 1;
    }

    std::vector<Utils::Vertex> vertices;
    std::vector<Utils::Triangle> indexes;

    parse_obj(argv[1], vertices, indexes);

    simplify(vertices, indexes, std::stoi(argv[3]));

    write_obj(argv[2], vertices, indexes);

    for (Utils::Vertex& v : vertices)
        std::cout << v;

    return 0;
}
