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

    // static const std::string tstos(const TileShape& enumVal) {
    //     return TileShapeToString.at(enumVal);
    // };


    Coordinate GetPlayerLocation() {
        return PlayerLocation;
    };

private:

    const int maxX;
    const int maxY;

    std::shared_ptr<std::map<Coordinate, TileState>> GameBoard;

    Coordinate PlayerLocation;
};

#endif // TILEGAMECONTROLLER_HPP
