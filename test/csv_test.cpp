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


TEST(CsvTest, TestGetMax_X_Y) {
    std::string filepath = "C:\\Users\\geary\\Projects\\TileGame\\data\\test.csv";
    std::unique_ptr<GameBoardBuilderInterface> test1 = std::make_unique<CsvGameBoardBuilder>(filepath);

    EXPECT_EQ(test1->GetMaxX(), 5);
    EXPECT_EQ(test1->GetMaxY(), 5);
}

TEST(CsvTest, TestGetGameTileShape) {
    std::string filepath = "C:\\Users\\geary\\Projects\\TileGame\\data\\test.csv";
    std::unique_ptr<GameBoardBuilderInterface> test1 = std::make_unique<CsvGameBoardBuilder>(filepath);

    EXPECT_EQ((*test1->GetGameTileShape()), TileShape::SQUARE);
}

TEST(CsvTest, TestGetGameBoard) {
    std::string filepath = "C:\\Users\\geary\\Projects\\TileGame\\data\\test.csv";
    std::unique_ptr<GameBoardBuilderInterface> test_builder = std::make_unique<CsvGameBoardBuilder>(filepath);

    Coordinate c1(0,2);
    Coordinate c2(0,3);
    Coordinate c3(2,0);

    std::shared_ptr<std::unordered_map<Coordinate, TileState>> test_board = test_builder->GetGameBoard();

    // iterating over all value of test_board 
    // std::unordered_map<Coordinate, TileState>::iterator itr; 
    // std::cout << "\nAll Elements : \n"; 
    // for (itr = test_board->begin(); itr != test_board->end(); itr++)
    //     std::cout << itr->first << std::endl; 

    TileState c1a = test_board->at(c1);
    TileState c2a = test_board->at(c2);
    TileState c3a = test_board->at(c3);

    EXPECT_EQ(c1a, TileState::NA);
    EXPECT_EQ(c2a, TileState::EMPTY);
    EXPECT_EQ(c3a, TileState::PLAYER);
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
