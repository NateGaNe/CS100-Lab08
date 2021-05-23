#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "op.hpp"
#include "base.hpp"

TEST(MultTest, MultTestWTwoNonZero){
	Op* five = new Op(5);
	Op* six = new Op(6);
	Mult* test = new Mult(five, six);
	EXPECT_EQ(test->evaluate(), 30);
	delete test;
}
TEST(MultTest, MultStringifyTwoNonZero){
	Op* five = new Op(5);
	Op* six = new Op(6);
	Mult* test = new Mult(five, six);
	EXPECT_EQ(test->stringify(), "(5.000000) * (6.000000)");

	delete test;
}
TEST(MultTest, MultTestwOneZero){
	Op* five = new Op(5);
	Op* zero = new Op(0);
	Mult* test = new Mult(five, zero);
	EXPECT_EQ(test->evaluate(), 0);
	delete test;
}
TEST(MultTest, MultDoubleTest){
	Op* five = new Op(5);
	Op* six = new Op(6);
	Op* ten = new Op(10);
	Mult* testOne = new Mult(five, six);
	Mult* testTwo = new Mult(testOne, ten);
	EXPECT_EQ(testTwo->evaluate(), 300);
	delete testTwo;
}

#endif //__MULT_TEST_HPP__
