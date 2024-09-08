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
