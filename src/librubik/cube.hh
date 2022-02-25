#pragma once

#include <istream>
#include <vector>

#include "piece.hh"
namespace rubik
{

    class Cube
    {
    public:
        Cube();
        Cube(std::vector<Piece> p);
        static Cube from_stream(std::istream& file_in);

        friend inline std::ostream& operator<<(std::ostream& os,
                                               const Cube& cube)
        {
            for (auto p : cube.pieces_)
                os << p;

            return os;
        }


    private:
        std::vector<Piece> pieces_;
    };
} // namespace rubik
