#pragma once

#include <iostream>

#include "color.hh"
#include "matrix3D.hh"
#include "move.hh"
#include "vector3D.hh"

namespace rubik
{
    class Piece
    {
    public:
        Vector3D<int> coords;
        Vector3D<Color> colors;

        enum Type
        {
            CORNER,
            CENTER,
            EDGE,
            NONE
        };

        Type get_type();

        // MOVES
        void do_move(Axis axis, Direction dir);
        void do_move(Face face, Direction dir);
    };

    // OPERATORS
    inline std::ostream& operator<<(std::ostream& os, const Piece& p)
    {
        return os << p.coords << " " << p.colors << "\n";
    }

    inline bool operator==(Piece& p1, Piece& p2)
    {
        return p1.coords == p2.coords && p1.colors == p2.colors;
    }
    inline bool operator!=(Piece& p1, Piece& p2)
    {
        return !(p1.coords == p2.coords && p1.colors == p2.colors);
    }

    inline bool operator<(Piece& p1, Piece& p2)
    {
        if (p1.coords.x < p2.coords.x)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y < p2.coords.y)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y == p2.coords.y
                 && p1.coords.z < p2.coords.z)
            return true;
        return false;
    }
    inline bool operator>(Piece& p1, Piece& p2)
    {
        if (p1.coords.x > p2.coords.x)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y > p2.coords.y)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y == p2.coords.y
                 && p1.coords.z > p2.coords.z)
            return true;
        return false;
    }

    inline bool operator<=(Piece& p1, Piece& p2)
    {
        if (p1 == p2)
            return true;

        if (p1.coords.x < p2.coords.x)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y < p2.coords.y)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y == p2.coords.y
                 && p1.coords.z < p2.coords.z)
            return true;
        return false;
    }
    inline bool operator>=(Piece& p1, Piece& p2)
    {
        if (p1 == p2)
            return true;

        if (p1.coords.x > p2.coords.x)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y > p2.coords.y)
            return true;
        else if (p1.coords.x == p2.coords.x && p1.coords.y == p2.coords.y
                 && p1.coords.z > p2.coords.z)
            return true;
        return false;
    }

} // namespace rubik
