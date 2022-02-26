#pragma once

#include <array>
#include <iostream>
#include <vector>

#include "vector3D.hh"

namespace rubik
{
    template <class T>
    class Matrix3D
    {
    public:
        inline Matrix3D(std::array<std::array<T, 3>, 3> values)
            : values(values)
        {}

        inline T at(int i, int j) const
        {
            return this->values[i][j];
        }

        Vector3D<T>
        operator*(const Vector3D<T>& v) const // matrix-vector product
        {
            Vector3D<T> n;
            n.x = at(0, 0) * v.x + at(0, 1) * v.y + at(0, 2) * v.z;
            n.y = at(1, 0) * v.x + at(1, 1) * v.y + at(1, 2) * v.z;
            n.z = at(2, 0) * v.x + at(2, 1) * v.y + at(2, 2) * v.z;
            return n;
        }

        void transpose() // flip the matrix over its diagonal
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    std::swap(values[i][j], values[j][i]);
                }
            }
        }

        std::array<std::array<T, 3>, 3> values;
    };

} // namespace rubik
