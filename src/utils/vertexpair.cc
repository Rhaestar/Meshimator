#include "vertexpair.hh"
#include "symmat.hh"

namespace Utils
{
    bool VertexPair::Replace(Utils::Vertex* v, Utils::Vertex* new_v)
    {
        if (*v == *v1_)
        {
            v1_ = new_v;
            return true;
        }

        if (*v == *v2_)
        {
            v2_ = new_v;
            return true;
        }

        return false;
    }

    float VertexPair::GetCost()
    {
        if (!cost_cached)
            ComputeCost();

        return optimal_cost;
    }

    Vector4& VertexPair::GetOptimalVertex()
    {
        if (!cost_cached)
            ComputeCost();

        return optimal_vertex;
    }

    void VertexPair::ComputeCost()
    {
        if (v1_ == nullptr || v2_ == nullptr)
            return;

        cost_cached = true;
        Vector4& final_vertex = v1_->GetPos();
        optimal_vertex = final_vertex;
        SymMat sum = v1_->GetMat() + v2_->GetMat();
        optimal_cost = (final_vertex * sum).dot(final_vertex);
    }
}
