#ifndef __TEST_MULTIPLE_CLASS_HPP__
#define __TEST_MULTIPLE_CLASS_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "pow.hpp"

TEST(CombinedEffort, addMultTest){
	Op* five = new Op(5);
	Op* seven = new Op(7);
	Op* ten = new Op(10);
	Mult* sevten = new Mult(seven, ten);
	Add* test = new Add(sevten, five);
	EXPECT_EQ(test->evaluate(), 75);
	delete test;
}
TEST(CombinedEffort, divAddTest){
	Op* five = new Op(5);
        Op* seven = new Op(7);
        Op* ten = new Op(10);
	Div* two = new Div(ten, five);
	Add* test = new Add(two, seven);
	EXPECT_EQ(test->evaluate(), 9);
	delete test;
}
TEST(CombinedEffort, divSubTest){
	Op* five = new Op(5);
        Op* seven = new Op(7);
        Op* ten = new Op(10);
	Div* two = new Div(ten, five);
	Sub* test = new Sub(seven,two);
	EXPECT_EQ(test->evaluate(), 5);
	delete test;
}
TEST(CombinedEffort, divPowTest){
	Op* five = new Op(5);
        Op* seven = new Op(7);
        Op* ten = new Op(10);
	Div* two = new Div(ten, five);
	Pow* test = new Pow(seven, two);
	EXPECT_EQ(test->evaluate(), 49);
	delete test;
}
TEST(CombinedEffort, divMultTest){
	Op* five = new Op(5);
        Op* seven = new Op(7);
        Op* ten = new Op(10);
	Div* two = new Div(ten, five);
	Mult* test = new Mult(two, seven);
	EXPECT_EQ(test->evaluate(), 14);
	delete test;
}
TEST(CombinedEffort, divMultAddSubPowTest){
	Op* five = new Op(5);
	Op* one = new Op(1);
        Op* seven = new Op(7);
	Op* three = new Op(3);
        Op* ten = new Op(10);
	Op* eleven = new Op(11);
	Div* two = new Div(ten, five);
	Mult* fourteen = new Mult(two, seven);
	Add* seventeen = new Add(fourteen, three);
	Sub* six = new Sub(seventeen, eleven);
	Pow* test = new Pow(six, one);
	EXPECT_EQ(test->evaluate(), 6);
	delete test;
}

#endif //__TEST_MULTIPLE_CLASS_HPP__
