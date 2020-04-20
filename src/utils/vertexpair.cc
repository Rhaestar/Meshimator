#include "vertexpair.hh"
#include "symmat.hh"

namespace Utils
{
    bool VertexPair::Replace(Utils::Vertex* new_v, Utils::Vertex* v)
    {
        cost_cached = false;
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

        SymMat sum = v1_->GetMat() + v2_->GetMat();
        float inv[16];
        if (sum.GetInverse(inv))
        {
            optimal_vertex.x = inv[3];
            optimal_vertex.y = inv[7];
            optimal_vertex.z = inv[11];
            optimal_vertex.h = inv[15];
            Vector4 temp = (optimal_vertex * sum);
            optimal_cost = optimal_vertex.dot(temp);

            return;
        }

        const Vector4& test_vertex1 = v1_->GetPos();
        const Vector4& test_vertex2 = v2_->GetPos();
        const Vector4& test_vertex3 = (v1_->GetPos() + v2_->GetPos()) / 2.f;


        float test_cost1 = ((test_vertex1 * sum).dot(test_vertex1));
        float test_cost2 = ((test_vertex2 * sum).dot(test_vertex2));
        float test_cost3 = ((test_vertex3 * sum).dot(test_vertex3));

        if (test_cost1 < test_cost2 && test_cost1 < test_cost3)
        {
            optimal_vertex = test_vertex1;
            optimal_cost = test_cost1;
        }
        else if (test_cost2 < test_cost3)
        {
            optimal_vertex = test_vertex2;
            optimal_cost = test_cost2;
        }
        else
        {
            optimal_vertex = test_vertex3;
            optimal_cost = test_cost3;
        }
    }
}
