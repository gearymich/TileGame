#ifndef TILEGAMECONTROLLER_HPP
#define TILEGAMECONTROLLER_HPP

#include <string>
#include <map>
#include <memory>
#include <Coordinate.hpp>
#include <GameStateEnum.hpp>

class TileGameController
{
public:

    TileGameController();

    static const std::string tstos(const TileShape& enumVal) {
        return TileShapeToString.at(enumVal);
    };


    Coordinate GetPlayerLocation() {
        return PlayerLocation;
    };

private:

    const int maxX;
    const int maxY;

    std::shared_ptr<std::map<Coordinate, TileState>> GameBoard;

    Coordinate PlayerLocation;

    static const inline std::map<TileShape, std::string> TileShapeToString = {
        {TileShape::SQUARE, "Square"}, 
        {TileShape::TRIANGLE, "Triangle"},
        {TileShape::HEXAGON, "Hexagon"},
    };
};

#endif // TILEGAMECONTROLLER_HPP
