#include "CsvGameBoardBuilder.hpp"

// constructor
CsvGameBoardBuilder::CsvGameBoardBuilder(const std::string& filepath) {
    GameBoard = std::make_shared<std::unordered_map<Coordinate, TileState>>();
    ReadCsv(filepath);
    ValidateGameBoard();
}

// method pulled from https://www.geeksforgeeks.org/csv-file-management-using-c/
void CsvGameBoardBuilder::ReadCsv(const std::string& filepath) {
    std::ifstream fin(filepath); // open 'filepath', read into OutputRow
    std::string line, cell_data;
    int RowNum = 0;

    while (!fin.eof()) {
        getline(fin, line);
        std::stringstream s(line); // used for breaking cell_datas
        int ColNum = 0;
        while (getline(s, cell_data, ',')) {
            if ((cell_data.size() != 1) && !std::isalnum(cell_data.back())) { // correct for EOL during csv read 
                cell_data = cell_data.substr(0, cell_data.size()-1);
            }
            if(RowNum == 0) { // row 0 reserved for metadata
                ReadMetaData(cell_data, ColNum); 
            } else { // generate coordinate from input
                if (MaxX  == 0 || MaxY == 0) {
                    throw std::invalid_argument( "MetaData Loaded Bad" );
                }
                ReadBoardData(RowNum-1, ColNum, cell_data);
            }
            ColNum++;
        }
        ColNum = 0;
        RowNum++;
    }

    fin.close();
}

void CsvGameBoardBuilder::ValidateGameBoard() {

};

void CsvGameBoardBuilder::ReadMetaData(const std::string& cell_data, int ColNum) {
    switch (ColNum) {
        case 0: // tile shape
            if (ValidTiles.find(cell_data) == ValidTiles.end()) {
                throw std::invalid_argument( "Bad TileShape value. Must be Square, Triangle, or Hexagon" );
            }
            GameTileShape = std::make_shared<TileShape>(StringToTileShape(cell_data));
            break;
        case 1: 
            MaxX = stoi(cell_data); 
            break;
        case 2: 
            MaxY = stoi(cell_data);
            break;
        default:
            throw std::invalid_argument( "received bad ColNum value" );
    }
}
void CsvGameBoardBuilder::ReadBoardData(int RowNum, int ColNum, const std::string& cell_data) {
    Coordinate NewCoordinate(RowNum, ColNum); 
    TileState NewTileState = StringToTileState(cell_data);
    GameBoard->insert({ NewCoordinate, NewTileState }); 
}