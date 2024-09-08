#ifndef CSVGAMEBOARDBUILDER_HPP
#define CSVGAMEBOARDBUILDER_HPP

#include "IGameBoardBuilder.hpp"

class CsvGameBoardBuilder : public IGameBoardBuilder
{
public:

    CsvGameBoardBuilder(
        std::shared_ptr<std::unordered_map<Coordinate, TileState>> aGameBoard,
        std::shared_ptr<TileShape> aGameTileShape,
        std::string filepath
    );

    void ReadCsv(std::string filepath);

protected:

    void SetGameBoard(std::shared_ptr<std::unordered_map<Coordinate, TileState>>) override;

    void SetGameTileShape(std::shared_ptr<TileShape>) override;

    void ValidateGameBoard() override;

    void ReadMetaData(std::string, int);
};

#endif // CSVGAMEBOARDBUILDER_HPP
