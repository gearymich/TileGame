#include "CsvGameBoardBuilder.hpp"

// constructor
CsvGameBoardBuilder::CsvGameBoardBuilder( 
        std::shared_ptr<std::unordered_map<Coordinate, TileState>> aGameBoard,
        std::shared_ptr<TileShape> aGameTileShape,
        std::string filepath) {

    SetGameBoard(aGameBoard);
    SetGameTileShape(aGameTileShape);

    ReadCsv(filepath);
    
    ValidateGameBoard();
}

// method pulled from https://www.geeksforgeeks.org/csv-file-management-using-c/
void CsvGameBoardBuilder::ReadCsv(std::string filepath) {
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
                Coordinate NewCoordinate(RowNum, ColNum); 
                TileState NewTileState = StringToTileState(cell_data);
                GameBoard->insert({ NewCoordinate, NewTileState }); 
            }
            ColNum++;
        }
        ColNum = 0;
        RowNum++;
    }

    fin.close();
}

void CsvGameBoardBuilder::SetGameBoard(std::shared_ptr<std::unordered_map<Coordinate, TileState>> aGameBoard) {
    GameBoard = aGameBoard;
};

void CsvGameBoardBuilder::SetGameTileShape(std::shared_ptr<TileShape> aGameTileShape) {
    GameTileShape = aGameTileShape;
};

void CsvGameBoardBuilder::ValidateGameBoard() {

};

void CsvGameBoardBuilder::ReadMetaData(std::string cell_data, int ColNum) {
    switch (ColNum) {
        case 0: // tile shape
            if (ValidTiles.find(cell_data) != ValidTiles.end()) {
                std::cout << cell_data << " is in the set!" << std::endl;
                std::shared_ptr<TileShape> GameTileShapePtr = std::make_shared<TileShape>(StringToTileShape(cell_data));
                SetGameTileShape(GameTileShapePtr);
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