#include <gtest/gtest.h>
#include "ComplexNumbers.h"

TEST(ComplexTests, DefaultConstructor) {
    Complex<int> c;
    EXPECT_EQ(c.GetP_Re(), 0);
    EXPECT_EQ(c.GetP_Im(), 0);
}

TEST(ComplexTests, ParametrizedConstructor) {
    Complex<double> c(3.0, 4.0);
    EXPECT_DOUBLE_EQ(c.GetP_Re(), 3.0);
    EXPECT_DOUBLE_EQ(c.GetP_Im(), 4.0);
}

TEST(ComplexTests, Addition) {
    Complex<float> a(2.0, 3.0);
    Complex<float> b(1.0, 2.0);
    Complex<float> result = a + b;
    EXPECT_FLOAT_EQ(result.GetP_Re(), 3.0);
    EXPECT_FLOAT_EQ(result.GetP_Im(), 5.0);
}

TEST(ComplexTests, Minus) {
    Complex<float> a(2.0, 3.0);
    Complex<float> b(1.0, 2.0);
    Complex<float> result = a - b;
    EXPECT_FLOAT_EQ(result.GetP_Re(), 1.0);
    EXPECT_FLOAT_EQ(result.GetP_Im(), 1.0);
}

TEST(ComplexTests, Multiplication) {
    Complex<double> a(1.0, 2.0);
    Complex<double> b(2.0, 3.0);
    Complex<double> result = a * b;
    EXPECT_DOUBLE_EQ(result.GetP_Re(), -4.0);
    EXPECT_DOUBLE_EQ(result.GetP_Im(), 7.0);
}

TEST(ComplexTests, AbsoluteValue) {
    Complex<int> c(3, 4);
    EXPECT_EQ(c.Abs(), 5);
}

TEST(ComplexTests, Pow) {
    Complex<float> c(2.0, 3.0);
    Complex<float> result = c.Pow(2);
    EXPECT_FLOAT_EQ(result.GetP_Re(), -5.0);
    EXPECT_FLOAT_EQ(result.GetP_Im(), 12.0);
}

TEST(ComplexTests, ComparisonToComplex) {
    Complex<int> a(3, 4);
    Complex<int> b(3, 4);
    Complex<int> c(1, 2);
    EXPECT_TRUE(a.CompareToComplex(b));
    EXPECT_FALSE(a.CompareToComplex(c));
}

TEST(ComplexTests, ComparisonToIntFloat) {
    Complex<int> a(5, 0);
    EXPECT_TRUE(a.CompareToIntFloat(5));
    EXPECT_FALSE(a.CompareToIntFloat(4));
}

TEST(ComplexTests, Division) {
    Complex<double> a(1.0, 2.0);
    Complex<double> b(2.0, 3.0);
    Complex<double> c(0.0, 0.0);
    Complex<double> result = a / b;
    EXPECT_NEAR(result.GetP_Re(), 0.615384615, 1e-6);
    EXPECT_NEAR(result.GetP_Im(), 0.076923076, 1e-6);
    EXPECT_THROW(a / c, std::runtime_error);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
