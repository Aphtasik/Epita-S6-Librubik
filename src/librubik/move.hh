#pragma once

namespace rubik
{
    enum class Axis
    {
        X,
        Y,
        Z
    };

    enum class Direction
    {
        CLOCKWISE,
        ANTI_CLOCKWISE
    };

    enum class Face
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        FRONT,
        BACK
    };
} // namespace rubik
