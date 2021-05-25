#ifndef MATHMLTEST_HPP
#define MATHMLTEST_HPP

#include "gtest/gtest.h"

#include "VistMathML.h"

TEST(MathML, regularAdd){
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* add = new Add(three, four);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(add), "<math>\n  <apply>\n    <plus/>\n    <cn>3</cn>\n    <cn>4</cn>\n  </apply>\n</math>");
}

#endif