#include <Coordinate.hpp>

// constructor
Coordinate::Coordinate(int x, int y) : x(x), y(y) {

}

bool Coordinate::operator==(const Coordinate& c2) const {
    return (x == c2.getX()) && (y == c2.getY());
}