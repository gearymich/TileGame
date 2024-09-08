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

    inline int GetMaxX() {return MaxX; };

    inline int GetMaxY() {return MaxY; };

    inline static const TileShape StringToTileShape(const std::string& val) {
        return StringToTileShapeTable.at(val);
    };

    inline static const TileState StringToTileState(const std::string& val) {
        return StringToTileStateTable.at(val);
    };



protected:

    void SetGameBoard(std::shared_ptr<std::unordered_map<Coordinate, TileState>>) override;

    void SetGameTileShape(std::shared_ptr<TileShape>) override;

    void ValidateGameBoard() override;

    void ReadMetaData(std::string, int);

    void SetTileShape(const std::string&);

    int MaxX, MaxY;

    static const inline std::map<std::string, TileShape> StringToTileShapeTable = {
        {"Square", TileShape::SQUARE}, 
        {"Triangle", TileShape::TRIANGLE},
        {"Hexagon", TileShape::HEXAGON}
    };

    static const inline std::map<std::string, TileState> StringToTileStateTable = {
        {"#", TileState::NA}, 
        {"P", TileState::PLAYER},
        {"O", TileState::EMPTY}
    };
};

#endif // CSVGAMEBOARDBUILDER_HPP
