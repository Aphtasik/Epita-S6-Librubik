#pragma once

#include <istream>
#include <vector>
#include <iterator>

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
        std::vector<Piece>::const_iterator begin() const;
        std::vector<Piece>::iterator begin();
        std::vector<Piece>::const_iterator end() const;
        std::vector<Piece>::iterator end();

        Piece find_piece(Vector3D<int> coords) const;
        Piece find_piece(Vector3D<Color> colors) const;


    private:
        std::vector<Piece> pieces_;
    };
} // namespace rubik
