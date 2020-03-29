#pragma once

#include "vector4.hh"
#include "vertex.hh"

namespace Utils
{
    class Vertex;

    class VertexPair
    {
    public:
        VertexPair(Vertex* v1, Vertex* v2)
            : v1_(v1)
              , v2_(v2)
              , cost_cached(false)
        {}

        Vertex* GetFirst() { return v1_; }
        Vertex* GetSecond() { return v2_; }
        void SetInvalid() { cost_cached = false; }

        float GetCost();
        Vector4& GetOptimalVertex();

    private:
        void ComputeCost();

        Vertex* v1_;
        Vertex* v2_;
        bool cost_cached;
        Vector4 optimal_vertex;
        float optimal_cost;
    };
}
