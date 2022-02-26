#include "f2l.hh"

namespace rubik::solver
{
    F2L::F2L(std::initializer_list<std::string> files)
    {
        files = files;
    }

    void F2L::load_patterns()
    {
        int i = 0;
        for (auto f : files)
        {
            if (i == 0)
                layer1_white_edges = parse_csv(f);
            if (i == 1)
                layer1_white_corners = parse_csv(f);
            else
                layer2_edges = parse_csv(f);
        }
    }

    void F2L::setup(Cube& cube)
    {
        (void)cube;
        return;
    }
    std::vector<Move> F2L::solve(Cube cube)
    {
        (void)cube;
        std::vector<Move> moves;
        return moves;
    }

} // namespace rubik::solver
