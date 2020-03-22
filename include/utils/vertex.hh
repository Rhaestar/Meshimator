#pragma once

#include "vector4.hh"
#include "symmat.hh"
#include "triangle.hh"
#include <iostream>
#include <vector>

namespace Utils
{
    class Vertex
    {
    public:
        Vertex() {}
        Vertex(const Vector4& pos)
            : pos_(pos)
            , deleted_(false)
            , Q_()
        {}
        
        Vector4& GetPos() { return pos_; }
        bool IsDeleted() { return deleted_; }

        void FillQ(std::vector<Vertex>& vertices);
        void AddTriangle(Triangle* ref);

        friend std::ostream& operator<<(std::ostream& out, const Vertex& v);

    private:
        Vector4 pos_;
        bool deleted_;
        SymMat Q_;
        std::vector<Triangle*> trefs_;
        //Add references to pairs
        //std::vector<Pair*> prefs;
    };
}
