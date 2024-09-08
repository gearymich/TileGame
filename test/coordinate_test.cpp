#include <gtest/gtest.h>
#include <Coordinate.hpp>
#include <string>

TEST(CoordinateTest1, Constructor) {
    Coordinate exp = Coordinate(1, 2);
    EXPECT_EQ(exp.getX(), 1);
    EXPECT_EQ(exp.getY(), 2);
}

TEST(CoordinateTest1, EqOperator) {
    Coordinate exp1 = Coordinate(1, 2);
    Coordinate exp2 = Coordinate(1, 2);
    EXPECT_EQ(exp1, exp2);
}