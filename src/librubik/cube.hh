#pragma once

#include <istream>
#include <iterator>
#include <vector>

#include "piece.hh"
namespace rubik
{

    class Cube
    {
    public:
        // Constructor
        Cube();
        Cube(std::vector<Piece> p);

        static Cube from_stream(std::istream& file_in);

        // Operator
        friend inline std::ostream& operator<<(std::ostream& os,
                                               const Cube& cube)
        {
            for (auto p : cube.pieces_)
                os << p;

            return os;
        }

        // Iterators
        std::vector<Piece>::const_iterator begin() const;
        std::vector<Piece>::iterator begin();
        std::vector<Piece>::const_iterator end() const;
        std::vector<Piece>::iterator end();

        // Find Piece
        Piece find_piece(Vector3D<int> coords) const;
        Piece find_piece(Vector3D<Color> colors) const;

        // Moves
        void do_move(Move move);
        void do_moves(std::vector<Move> moves);
        void undo_move(Move move);
        void undo_moves(std::vector<Move> moves);

    private:
        std::vector<Piece> pieces_;
    };
} // namespace rubik
