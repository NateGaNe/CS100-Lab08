#ifndef POW_TEST_HPP
#define POW_TEST_HPP

#include "gtest/gtest.h"

#include "pow.hpp"
#include "base.hpp"

TEST(PowerTest, Power){
	Base* eight = new Op(8);
	Base* ten = new Op(10);
	Base* test = new Pow(eight, ten);
	EXPECT_EQ(test->evaluate(), 1073741824);
	delete test;
}
#endif
