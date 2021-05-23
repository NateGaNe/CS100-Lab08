#ifndef ADD_TEST_HPP
#define ADD_TEST_HPP

#include "gtest/gtest.h"

#include "add.hpp"
#include "base.hpp"
TEST(AdditionTest, Addition){
	Base* eight = new Op(8);
	Base* ten = new Op(10);
	Base* test = new Add(eight, ten);
	EXPECT_EQ(test->evaluate(), 18);
	delete test;
}

#endif
