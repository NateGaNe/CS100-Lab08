#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
    delete test;

}

TEST(OpTest, OpStringifyNonZero){
   Op* test = new Op(8);
   EXPECT_EQ(test->stringify(), "8.000000");
   delete test;

}

TEST(OpTest, OpStringifyZero){
   Op* test = new Op(0);
   EXPECT_EQ(test->stringify(), "0.000000");
   delete test;

}
TEST(OpTest, OpStringifyNegative){
   Op* test = new Op(-1);
   EXPECT_EQ(test->stringify(), "-1.000000");
   delete test;
}
#endif //__OP_TEST_HPP__
