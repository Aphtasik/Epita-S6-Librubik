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
        switch (axis)
        {
        case Axis::X:
            do_move(Face::RIGHT, dir);
            break;
        case Axis::Y:
            do_move(Face::UP, dir);
            break;
        case Axis::Z:
            do_move(Face::FRONT, dir);
            break;
        }
    }

    void Piece::do_move(Face face, Direction dir)
    {
        std::array<std::array<int, 3>, 3> rxmat = {
            { { 1, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 } }
        };
        Matrix3D<int> rx = Matrix3D<int>(rxmat);

        std::array<std::array<int, 3>, 3> rymat = {
            { { 0, 0, 1 }, { 0, 1, 0 }, { -1, 0, 0 } }
        };
        Matrix3D<int> ry = Matrix3D<int>(rymat);

        std::array<std::array<int, 3>, 3> rzmat = {
            { { 0, -1, 0 }, { 1, 0, 0 }, { 0, 0, 1 } }
        };
        Matrix3D<int> rz = Matrix3D<int>(rzmat);

        Color tmp;

        switch (face)
        {
        case Face::FRONT:
            if (dir == Direction::CLOCKWISE)
                rx.transpose();
            this->coords = rx * this->coords;
            tmp = colors.y;
            colors.y = colors.z;
            colors.z = tmp;
            break;
        case Face::BACK:
            if (dir == Direction::ANTI_CLOCKWISE)
                rx.transpose();
            this->coords = rx * this->coords;
            tmp = colors.z;
            colors.z = colors.y;
            colors.y = tmp;
            break;
        case Face::RIGHT:
            if (dir == Direction::CLOCKWISE)
                ry.transpose();
            this->coords = ry * this->coords;
            tmp = colors.x;
            colors.x = colors.z;
            colors.z = tmp;
            break;
        case Face::LEFT:
            if (dir == Direction::ANTI_CLOCKWISE)
                ry.transpose();
            this->coords = ry * this->coords;
            tmp = colors.z;
            colors.z = colors.x;
            colors.x = tmp;
            break;
        case Face::UP:
            if (dir == Direction::CLOCKWISE)
                rz.transpose();
            this->coords = rz * this->coords;
            tmp = colors.y;
            colors.y = colors.x;
            colors.x = tmp;
            break;
        case Face::DOWN:
            if (dir == Direction::ANTI_CLOCKWISE)
                rz.transpose();
            this->coords = rz * this->coords;
            tmp = colors.x;
            colors.x = colors.y;
            colors.y = tmp;
            break;
        }
    }
} // namespace rubik
