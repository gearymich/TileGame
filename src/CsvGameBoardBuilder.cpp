#include "CsvGameBoardBuilder.hpp"

// constructor
CsvGameBoardBuilder::CsvGameBoardBuilder(const std::string& filepath) {
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
            if(RowNum == 0) { // row 0 reserved for metadata
                ReadMetaData(cell_data, ColNum); 
            } else { // generate coordinate from input
                ReadBoardData(RowNum, ColNum, cell_data);
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
            if (ValidTiles.find(cell_data) != ValidTiles.end()) {
                std::cout << cell_data << " is in the set!" << std::endl;
                GameTileShape = std::make_shared<TileShape>(StringToTileShape(cell_data));
            } else {
                std::cout << cell_data << " is not in the set." << std::endl;
            }
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
