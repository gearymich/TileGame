#ifndef IGAMEBOARDBUILDER_HPP
#define IGAMEBOARDBUILDER_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <stdexcept>

#include "Coordinate.hpp"
#include "GameStateEnum.hpp"

class IGameBoardBuilder
{
public:

    inline IGameBoardBuilder() {};
    virtual inline ~IGameBoardBuilder() {};

    std::shared_ptr<std::unordered_map<Coordinate, TileState>> GameBoard;

    std::shared_ptr<TileShape> GameTileShape;

protected:

    virtual void SetGameBoard(std::shared_ptr<std::unordered_map<Coordinate, TileState>>) = 0;

    virtual void SetGameTileShape(std::shared_ptr<TileShape>) = 0;

    virtual void ValidateGameBoard() = 0;

    std::set<std::string> ValidTiles = { "Square", "Triangle", "Hexagon" };

private:
};

#endif // IGAMEBOARDBUILDER_HPP
