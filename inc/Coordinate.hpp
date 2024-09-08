#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <string>
#include <unordered_map>
#include <GameStateEnum.hpp>

class Coordinate {
public:

    Coordinate(int x, int y);

    int getX() const { return x; }
    int getY() const { return y; }

    inline bool operator==(const Coordinate& c2) const {
        return (x == c2.getX()) && (y == c2.getY());
    }

private:

    const int x;
    const int y;


};

// Hash function specialization for Coordinate
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
