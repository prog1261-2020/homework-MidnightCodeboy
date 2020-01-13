#include "gtest/gtest.h"
#include "Vector2D.h"


TEST(Vector2DTestSuite, constructorTest01) {
    Vector2D v1(1, 1);

    std::string expectedResult = "(1, 1)";
    std::string result = v1.toString();

    EXPECT_EQ(expectedResult, result);
}


TEST(Vector2DTestSuite, equalsTest01) {
    Vector2D v1(1, 1);
    Vector2D v2(1, 1);

    EXPECT_TRUE(v1 == v2);
}


TEST(Vector2DTestSuite, equalsTest02) {
    Vector2D v1(1, 1);
    Vector2D v2(2, 1);

    EXPECT_FALSE(v1 == v2);
}


TEST(Vector2DTestSuite, notEqualsTest01) {
    Vector2D v1(5, 1);
    Vector2D v2(1, 1);

    EXPECT_TRUE(v1 != v2);
}


TEST(Vector2DTestSuite, notEqualsTest02) {
    Vector2D v1(1, 1);
    Vector2D v2(1, 1);

    EXPECT_FALSE(v1 != v2);
}