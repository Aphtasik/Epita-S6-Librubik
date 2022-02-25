#include "piece.hh"

namespace rubik
{
    Piece::Type Piece::get_type()
    {
        int count = 0;

        if (colors.x == Color::NONE)
            count++;
        if (colors.y == Color::NONE)
            count++;
        if (colors.z == Color::NONE)
            count++;

        if (count == 0)
            return Piece::Type::CORNER;
        else if (count == 1)
            return Piece::Type::EDGE;
        else if (count == 2)
            return Piece::Type::CENTER;
        else
            return Piece::Type::NONE;
    }
} // namespace rubik
