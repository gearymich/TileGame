#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <string>
#include <unordered_map>
#include <GameStateEnum.hpp>
#include <iostream>

class Coordinate {
public:
    inline Coordinate(int x, int y) : x(x), y(y) {};

    int getX() const { return x; }
    int getY() const { return y; }

    inline bool operator==(const Coordinate& c2) const {
        return (x == c2.getX()) && (y == c2.getY());
    }

    // Overload << operator to print coordinate values
    friend std::ostream& operator<<(std::ostream& os, const Coordinate& coord) {
        os << "(" << coord.getX() << ", " << coord.getY() << ")";
        return os;
    }

private:
    const int x;
    const int y;
};

namespace std {
    template <>
    struct hash<Coordinate> {
        std::size_t operator()(const Coordinate& c) const {
            // Combine the hash values of x and y
            return std::hash<int>()(c.getX()) ^ (std::hash<int>()(c.getY()) << 1);
        }
    };
}

#endif // COORDINATE_HPP
