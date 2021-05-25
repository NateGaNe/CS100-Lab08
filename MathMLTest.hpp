#ifndef MATHMLTEST_HPP
#define MATHMLTEST_HPP

#include "gtest/gtest.h"

#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "VisitorLaTex.hpp"
#include "VistMathML.h"
//#include "VistMathML.h"
//#include "base.hpp"
//#include "iterator.hpp"
TEST(MathML, regularAdd){
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* add = new Add(three, four);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(add), "<math>\n  <apply>\n    <plus/>\n    <cn>3.000000</cn>\n    <cn>4.000000</cn>\n  </apply>\n</math>");
}


#endif
