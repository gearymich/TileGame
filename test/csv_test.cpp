#include <gtest/gtest.h>
#include <GameBoardBuilderInterface.hpp>
#include <CsvGameBoardBuilder.hpp>
#include <string>


// invoke new game --> [game board builder] --> load game 

// output data:
// game metadata (max X, max Y, TileShape)
// game board object (as seen on csv) 

// does the builder get invoked by 'ConfigData BuildNewGame()' in the Controller? sounds nice
// then do LoadGame(ConfigData)

TEST(CsvTest, Test1) {
    // std::shared_ptr<std::unordered_map<Coordinate, TileState>> TestGameBoard = std::make_shared<std::unordered_map<Coordinate, TileState>>();
    // std::shared_ptr<TileShape> TestGameTile = std::make_shared<TileShape>(TileShape::SQUARE);
    std::string filepath = "C:\\Users\\geary\\Projects\\TileGame\\data\\test.csv";
    std::unique_ptr<GameBoardBuilderInterface> test1 = std::make_unique<CsvGameBoardBuilder>(filepath);
}

TEST(CsvTest, StringToTileState) {
    TileState test1 = CsvGameBoardBuilder::StringToTileState(std::string("#"));
    EXPECT_EQ(test1, TileState::NA);

    TileState test2 = CsvGameBoardBuilder::StringToTileState(std::string("P"));
    EXPECT_EQ(test2, TileState::PLAYER);
    
    TileState test3 = CsvGameBoardBuilder::StringToTileState(std::string("O"));
    EXPECT_EQ(test3, TileState::EMPTY);
}

TEST(CsvTest, StringToTileShape) {
    TileShape test1 = CsvGameBoardBuilder::StringToTileShape(std::string("Square"));
    EXPECT_EQ(test1, TileShape::SQUARE);

    TileShape test2 = CsvGameBoardBuilder::StringToTileShape(std::string("Triangle"));
    EXPECT_EQ(test2, TileShape::TRIANGLE);
    
    TileShape test3 = CsvGameBoardBuilder::StringToTileShape(std::string("Hexagon"));
    EXPECT_EQ(test3, TileShape::HEXAGON);
}
