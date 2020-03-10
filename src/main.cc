#include <iostream>

int main(int argc, char* /*argv*/[])
{
    if (argc != 4)
    {
        std::cerr << "USAGE: ./meshimator input_file output_file target\n";
        return 1;
    }
    return 0;
}
