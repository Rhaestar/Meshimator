#pragma once

#include "vector4.hh"
#include "symmat.hh"
#include "triangle.hh"
#include "vertexpair.hh"
#include <iostream>
#include <vector>

namespace Utils
{
    class VertexPair;

    class Vertex
    {
    public:
        Vertex() {}
        Vertex(const Vector4& pos, size_t index)
            : pos_(pos)
            , index_(index)
            , deleted_(false)
            , Q_()
        {}

        /*Vertex(const Vertex& v)
            : pos_(v.pos_)
            , deleted_(false)
            , Q_()
        {}*/
        
        Vector4& GetPos() { return pos_; }
        bool IsDeleted() { return deleted_; }
        SymMat GetMat() { return Q_; }
        size_t GetIndex() { return index_; }

        void Delete();
        void FillQ(std::vector<Vertex>& vertices);
        void AddTriangle(Triangle* ref);
        void AddPair(VertexPair* ref);
        bool CheckPair(const Vertex& v);

        bool operator==(const Vertex& v) { return index_ == v.index_; }
        bool operator!=(const Vertex& v) { return index_ != v.index_; }

        friend std::ostream& operator<<(std::ostream& out, const Vertex& v);

    private:
        Vector4 pos_;
        size_t index_;
        bool deleted_;
        SymMat Q_;
        std::vector<Triangle*> trefs_;
        std::vector<VertexPair*> prefs_;
    };
}
