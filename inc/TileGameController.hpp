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

    inline Coordinate GetPlayerLocation() { return PlayerLocation; };

    bool MovePlayer(Coordinate to);

private:

    const int maxX;
    const int maxY;

    std::shared_ptr<std::map<Coordinate, TileState>> GameBoard;

    Coordinate PlayerLocation;
};

#endif // TILEGAMECONTROLLER_HPP
