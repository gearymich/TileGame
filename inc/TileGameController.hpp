#ifndef TILEGAMECONTROLLER_HPP
#define TILEGAMECONTROLLER_HPP

#include <string>
#include <map>
#include <Coordinate.hpp>
#include <GameStateEnum.hpp>

class TileGameController
{
public:

    Coordinate GetPlayerLocation() {
        return PlayerLocation;
    };

private:

    std::map<Coordinate, TileState> GameState;

    Coordinate PlayerLocation;

};

#endif // TILEGAMECONTROLLER_HPP
