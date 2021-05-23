#ifndef SUB_TEST_HPP
#define SUB_TEST_HPP

#include "gtest/gtest.h"

#include "sub.hpp"
#include "base.hpp"

TEST(SubtractionTest, Subtraction){
	Base* eight = new Op(8);
	Base* ten = new Op(10);
	Base* test = new Sub(eight, ten);
	EXPECT_EQ(test->evaluate(), -2);
	delete test;
}
TEST(SubtractionTest, Subtraction2){
	Base* eight = new Op(8);
	Base* ten = new Op(10);
	Base* test = new Sub(ten, eight);
	EXPECT_EQ(test->evaluate(), 2);
	delete test;
}
#endif
