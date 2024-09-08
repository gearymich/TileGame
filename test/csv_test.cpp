#include <gtest/gtest.h>
#include <IGameBoardBuilder.hpp>
#include <CsvGameBoardBuilder.hpp>
#include <string>

TEST(CsvTest, Test1) {
    std::shared_ptr<std::unordered_map<Coordinate, TileState>> TestGameBoard = std::make_shared<std::unordered_map<Coordinate, TileState>>();
    std::shared_ptr<TileShape> TestGameTile = std::make_shared<TileShape>(TileShape::SQUARE);
    std::string filepath = "C:\\Users\\geary\\Projects\\TileGame\\data\\test.csv";
    std::unique_ptr<IGameBoardBuilder> t = std::make_unique<CsvGameBoardBuilder>(TestGameBoard, TestGameTile, filepath);
    EXPECT_EQ(1, 1);
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
