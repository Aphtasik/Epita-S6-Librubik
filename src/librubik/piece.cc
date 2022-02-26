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

    void Piece::do_move(Axis axis, Direction dir)
    {
        std::array<std::array<int, 3>, 3> rxmat = {
            { { 1, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 } }
        };
        Matrix3D<int> rx = Matrix3D<int>(rxmat);

        std::array<std::array<int, 3>, 3> rymat = {
            { { 0, 0, 1 }, { 0, 1, 0 }, { -1, 0, 1 } }
        };
        Matrix3D<int> ry = Matrix3D<int>(rymat);

        std::array<std::array<int, 3>, 3> rzmat = {
            { { 0, -1, 0 }, { 1, 0, 0 }, { 0, 0, 1 } }
        };
        Matrix3D<int> rz = Matrix3D<int>(rzmat);

        switch (axis)
        {
        case Axis::X:
            if (dir == Direction::ANTI_CLOCKWISE)
                rx.transpose();
            this->coords = rx * this->coords;
            break;
        case Axis::Y:
            if (dir == Direction::ANTI_CLOCKWISE)
                ry.transpose();
            this->coords = ry * this->coords;
            break;
        case Axis::Z:
            if (dir == Direction::ANTI_CLOCKWISE)
                rz.transpose();
            this->coords = rz * this->coords;
            break;
        }
    }

    void Piece::do_move(Face face, Direction dir)
    {
        switch (face)
        {
        case (Face::UP):
            do_move(Axis::Z, dir);
            break;
        case (Face::DOWN):
            do_move(Axis::Z, dir);
            break;
        case (Face::LEFT):
            do_move(Axis::X, dir);
            break;
        case (Face::RIGHT):
            do_move(Axis::Y, dir);
            break;
        case (Face::FRONT):
            do_move(Axis::X, dir);
            break;
        default:
            do_move(Axis::X, dir);
            break;
        }
    }
} // namespace rubik
