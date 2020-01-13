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

// Test less than for true and false

TEST(Vector2DTestSuite, lessThanTest01) {
    Vector2D v1(1, 1);
    Vector2D v2(3, 4);

    EXPECT_TRUE(v1 < v2);
}

TEST(Vector2DTestSuite, lessThanTest02) {
    Vector2D v1(1, 1);
    Vector2D v2(3, 4);

    EXPECT_FALSE(v2 < v1);
}

// Test greater than for true and false

TEST(Vector2DTestSuite, greaterThanTest01) {
    Vector2D v1(3, 4);
    Vector2D v2(1, 1);

    EXPECT_TRUE(v1 > v2);
}

TEST(Vector2DTestSuite, greaterThanTest02) {
    Vector2D v1(3, 4);
    Vector2D v2(1, 1);

    EXPECT_FALSE(v2 > v1);
}

// Test less than or equal to for true and false

TEST(Vector2DTestSuite, lessThanEqualTest01) {
    Vector2D v1(1, 1);
    Vector2D v2(3, 4);

    EXPECT_TRUE(v1 <= v2);
}

TEST(Vector2DTestSuite, lessThanEqualTest02) {
    Vector2D v1(1, 1);
    Vector2D v2(3, 4);

    EXPECT_FALSE(v2 <= v1);
}

TEST(Vector2DTestSuite, lessThanEqualTest03) {
    Vector2D v1(3, 4);
    Vector2D v2(3, 4);

    EXPECT_TRUE(v2 <= v1);
}

// Test greater than or equal to for true and false

TEST(Vector2DTestSuite, greaterThanEqualTest01) {
    Vector2D v1(3, 4);
    Vector2D v2(1, 1);

    EXPECT_TRUE(v1 >= v2);
}

TEST(Vector2DTestSuite, greaterThanEqualTest02) {
    Vector2D v1(3, 4);
    Vector2D v2(1, 1);

    EXPECT_FALSE(v2 >= v1);
}

TEST(Vector2DTestSuite, greaterThanEqualTest03) {
    Vector2D v1(3, 4);
    Vector2D v2(3, 4);

    EXPECT_TRUE(v2 >= v1);
}