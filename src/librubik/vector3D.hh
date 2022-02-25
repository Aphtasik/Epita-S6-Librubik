#pragma once

#include <iostream>

namespace rubik
{
    template <class T>
    class Vector3D
    {
    public:
        inline bool operator==(const Vector3D& val)
        {
            return x == val.x && y == val.y && z == val.z;
        }

        inline bool operator!=(const Vector3D& val)
        {
            return !(x == val.x && y == val.y && z == val.z);
        }

        T x;
        T y;
        T z;
    };


    template <class T>
    inline std::ostream& operator<<(std::ostream& os, const Vector3D<T>& val)
    {
        return os << "(" << val.x << "," << val.y << "," << val.z << ")";
    }
} // namespace rubik
