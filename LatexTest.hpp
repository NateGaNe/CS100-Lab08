#ifndef LATEXTEST_HPP
#define LATEXTEST_HPP

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
//#include "VistMathML.h"

// get it cuz laTEX
TEST(LaTest, add){
    Base* three = new Op(3);
    Base* two = new Op(2);
    Base* add = new Add(three, two);
    VisitorLaTeX test;
    EXPECT_EQ( test.PrintLaTeX(add), "${({3.000000}+{2.000000})}$");
    delete three;
    delete two;
    delete add;
}  

TEST(LaTest, sub){
    Base* five = new Op(5);
    Base* four = new Op(4);
    Base* sub = new Sub(five, four);
    VisitorLaTeX test;
    EXPECT_EQ( test.PrintLaTeX(sub), "${({5.000000}-{4.000000})}$");
    delete five;
    delete four;
    delete sub;
}

TEST(LaTest, mult){
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* mult = new Mult(two, four);
    VisitorLaTeX test;
    EXPECT_EQ( test.PrintLaTeX(mult), "${({2.000000}\\cdot{4.000000})}$");
    delete two;
    delete four;
    delete mult;
}

TEST(LaTest,Frac){
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* div = new Div(four, two);
    VisitorLaTeX test;
    EXPECT_EQ( test.PrintLaTeX(div), "${\\frac{{4.000000}}{{2.000000}}}$");
    delete four;
    delete two;
    delete div;
}

TEST(LaTest, Pow){
    Base* eight = new Op(8);
    Base* four = new Op(4);
    Base* pow = new Pow(eight, four);
    VisitorLaTeX test;
    EXPECT_EQ( test.PrintLaTeX(pow), "${({8.000000}^{4.000000})}$");
    delete eight;
    delete four;
    delete pow;
}

TEST(LaTest, multiple){
    Base* five = new Op(5);
    Base* ten = new Op(10);
    Base* one = new Op(1);
    Base* four = new Op(4);
    Base* fifteen = new Op(15);
    Base* nine = new Op(9);
    Base* pow = new Pow(nine, ten);
    Base* sub = new Sub(fifteen, one);
    Base* add = new Add(four, five);
    Base* add2 = new Add(pow, sub);
    Base* end = new Mult(add2, add);
    VisitorLaTeX test;
    EXPECT_EQ( test.PrintLaTeX(end), "${((({9.000000}^{10.000000})+({15.000000}-{1.000000}))\\cdot({4.000000}+{5.000000}))}$");
    delete five;
    delete ten;
    delete one;
    delete four;
    delete fifteen;
    delete nine;
    delete pow;
    delete sub;
    delete add;
    delete add2;
    delete end;
}

#endif
