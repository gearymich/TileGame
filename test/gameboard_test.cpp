// #include <gtest/gtest.h>
// #include <Coordinate.hpp>
// #include <string>
// #include <gmock/gmock.h>  // Brings in gMock.

// class MockTurtle : public Turtle {
//     // https://google.github.io/googletest/gmock_for_dummies.html
// public:
//     MOCK_METHOD(void, PenUp, (), (override));
//     MOCK_METHOD(void, PenDown, (), (override));
//     MOCK_METHOD(void, Forward, (int distance), (override));
//     MOCK_METHOD(void, Turn, (int degrees), (override));
//     MOCK_METHOD(void, GoTo, (int x, int y), (override));
//     MOCK_METHOD(int, GetX, (), (const, override));
//     MOCK_METHOD(int, GetY, (), (const, override));
// };