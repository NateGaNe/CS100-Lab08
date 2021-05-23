#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "op.hpp"

TEST(DivTest, DivTestWithNonZero){
	Op* thirtyNine = new Op(39);
	Op* thirteen = new Op(13);
	Div* test = new Div(thirtyNine, thirteen);
	EXPECT_EQ(test->evaluate(), 3);
	delete test;
}
TEST(DivTest, DivStringifyWithNonZero){
	Op* thirtyNine = new Op(39);
	Op* thirteen = new Op(13);
	Div* test = new Div(thirtyNine, thirteen);

	EXPECT_EQ(test->stringify(), "(39.000000) / (13.000000)");

	delete test;
}

TEST(DivTest, DivTestwOneZero){
        Op* five = new Op(5);
        Op* zero = new Op(0);
        Div* test = new Div(zero, five);
        EXPECT_EQ(test->evaluate(), 0);
	delete test;
}

TEST(DivTest, DivDoubleTest){
        Op* five = new Op(5);
        Op* two = new Op(2);
        Op* ten = new Op(10);
        Div* testOne = new Div(ten, five);
        Div* testTwo = new Div(testOne, two);
        EXPECT_EQ(testTwo->evaluate(), 1);
	delete testTwo;
}
#endif //__DIV_TEST_HPP__

