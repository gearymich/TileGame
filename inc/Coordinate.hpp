#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <string>
#include <map>
#include <GameStateEnum.hpp>

class Coordinate {
public:

    enum class TileShape {
        SQUARE,
        TRIANGLE,
        HEXAGON
    };

    Coordinate(int x, int y);

    static const std::string tstos(const TileShape& enumVal) {
        return TileShapeToString.at(enumVal);
    };

    int getX() const { return x; }
    int getY() const { return y; }

    bool operator==(const Coordinate& c2) const;

private:

    const int x;
    const int y;

    static const inline std::map<TileShape, std::string> TileShapeToString = {
        {TileShape::SQUARE, "Square"}, 
        {TileShape::TRIANGLE, "Triangle"},
        {TileShape::HEXAGON, "Hexagon"},
    };

};

#endif // COORDINATE_HPP
