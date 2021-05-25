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
    delete add;
}

TEST(MathML, regularSub){
    Base* fifteen = new Op(15);
    Base* three = new Op(3);
    Base* sub = new Sub(fifteen, three);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(sub),  "<math>\n  <apply>\n    <minus/>\n    <cn>15.000000</cn>\n    <cn>3.000000</cn>\n  </apply>\n</math>" );
    delete sub;
}

TEST(MathML, regularMult){
    Base* five = new Op(5);
    Base* three = new Op(3);
    Base* mult = new Mult(five, three);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(mult),  "<math>\n  <apply>\n    <times/>\n    <cn>5.000000</cn>\n    <cn>3.000000</cn>\n  </apply>\n</math>");
    delete mult;
}

TEST(MathML, regularPow){
    Base* eight = new Op(8);
    Base* two = new Op(2);
    Base* pow = new Pow(eight, two);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(pow),  "<math>\n  <apply>\n    <power/>\n    <cn>8.000000</cn>\n    <cn>2.000000</cn>\n  </apply>\n</math>");
    delete pow;
}

TEST(MathML, regDiv){
    Base* eight = new Op(8);
    Base* two = new Op(2);
    Base* div = new Div(eight, two);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(div),  "<math>\n  <apply>\n    <divide/>\n    <cn>8.000000</cn>\n    <cn>2.000000</cn>\n  </apply>\n</math>");
    delete div;
}

TEST(MathML, twoFunctions){
    Base* eight = new Op(8);
    Base* fifteen = new Op(15);
    Base* thirteen = new Op(13);
    Base* minus = new Sub(fifteen, thirteen);
    Base* div = new Div(eight, minus);
    VisitMathML test;
    EXPECT_EQ(test.PrintMathML(div),  "<math>\n  <apply>\n    <divide/>\n    <cn>8.000000</cn>\n    <apply>\n      <minus/>\n      <cn>15.000000</cn>\n      <cn>13.000000</cn>\n    </apply>\n  </apply>\n</math>");
    delete div;
}

//TEST(MathML,moreThanOne){
  //  Base* two = new Op(2);
    //Base* five = new Op(5);
    //Base* mult = new Mult(two, five);
    //Base* pow = new Pow(five, two);
    //Base* div = new Div(mult, pow);
    //VisitMathML test;
    //EXPECT_EQ( test.PrintMathML(div), "<math>\n  <apply>\n    <divide/>\n    <apply>\n      <times/>\n      <cn>2.000000</cn>\n      <cn>5.000000</cn>\n    </apply>\n    <apply>\n      <power/>\n      <cn>5.000000</cn>\n      <cn>2.000000</cn>\n    </apply>\n  </apply>\n</math>");
   // delete div;
//}

#endif
