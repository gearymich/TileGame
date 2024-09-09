#ifndef GAMEBOARDBUILDERINTERFACE_HPP
#define GAMEBOARDBUILDERINTERFACE_HPP

#include <string>
#include <map>
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

class GameBoardBuilderInterface
{
public:

    inline GameBoardBuilderInterface() {};
    virtual inline ~GameBoardBuilderInterface() {};

    virtual std::shared_ptr<std::unordered_map<Coordinate, TileState>> GetGameBoard() = 0;

    virtual std::shared_ptr<TileShape> GetGameTileShape() = 0;

protected:

    virtual void ValidateGameBoard() = 0;

    std::set<std::string> ValidTiles = { "Square", "Triangle", "Hexagon" };

    std::shared_ptr<std::unordered_map<Coordinate, TileState>> GameBoard;

    std::shared_ptr<TileShape> GameTileShape;

    
private:
};

#endif // GAMEBOARDBUILDERINTERFACE_HPP
