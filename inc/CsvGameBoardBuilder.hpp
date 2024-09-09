#ifndef CSVGAMEBOARDBUILDER_HPP
#define CSVGAMEBOARDBUILDER_HPP

#include "GameBoardBuilderInterface.hpp"

class CsvGameBoardBuilder : public GameBoardBuilderInterface
{
public:

    CsvGameBoardBuilder(const std::string& filepath);

    void ReadCsv(const std::string& filepath);

    void ReadBoardData(int RowNum, int ColNum, const std::string& cell_data);

    inline int GetMaxX() {return MaxX; };

    inline int GetMaxY() {return MaxY; };

    inline static const TileShape StringToTileShape(const std::string& val) {
        return StringToTileShapeTable.at(val);
    };

    inline static const TileState StringToTileState(const std::string& val) {
        return StringToTileStateTable.at(val);
    };

    inline std::shared_ptr<std::unordered_map<Coordinate, TileState>> GetGameBoard() override { return GameBoard; };

    inline std::shared_ptr<TileShape> GetGameTileShape() override { return GameTileShape; };

protected:

    void ValidateGameBoard() override;

    void ReadMetaData(const std::string&, int);

    // void SetTileShape(const std::string&);

    int MaxX, MaxY;

    // FUTURE: move from builder to approp class
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
