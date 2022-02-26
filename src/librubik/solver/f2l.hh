#pragma once

#include "../piece.hh"
#include "parse-csv.hh"
#include "solver.hh"

// First 2 Layers

namespace rubik::solver
{
    class F2L : public Solver
    {
    public:
        F2L(std::initializer_list<std::string> files);
        void load_patterns();
        void setup(Cube& cube);
        std::vector<Move> solve(Cube cube);

        std::initializer_list<std::string> files;

        std::vector<std::vector<std::string>> layer1_white_corners;
        std::vector<std::vector<std::string>> layer1_white_edges;
        std::vector<std::vector<std::string>> layer2_edges;
    };
} // namespace rubik::solver
