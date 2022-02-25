#pragma once

#include <iostream>

namespace rubik
{
    enum class Color
    {
        YELLOW,
        RED,
        GREEN,
        WHITE,
        BLUE,
        ORANGE,
        NONE
    };

    inline std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        if (color == Color::YELLOW)
            return os << 'Y';
        else if (color == Color::RED)
            return os << 'R';
        else if (color == Color::GREEN)
            return os << 'G';
        else if (color == Color::WHITE)
            return os << 'W';
        else if (color == Color::BLUE)
            return os << 'B';
        else
            return os << 'O';
    }
} // namespace rubik
