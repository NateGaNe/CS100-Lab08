#include <iostream>

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
int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
	Base* one = new Op(1);
	Base* five = new Op(5);
	Base* six = new Op(6);
	Base* eight = new Op(8);
	Base* nine = new Op(9);
	Base* ten = new Op(10);
    Base* mult = new Mult(seven, three);
	Base* add = new Add(four, two);
	Base* sub = new Sub(five, one);
	Base* div = new Div (six, eight);
	Base* div2 = new Div(div, mult);
	Base* pow = new Pow(nine,ten);
	Base* firstTest = new Add(pow, sub);
	Base* secondTest = new Mult(firstTest, add);
	VisitorLaTeX obj, obj2, obj3, obj4, obj10,obj11;
	VisitMathML obj5, obj6, obj7, obj8, obj9,obj12;
	std::cout << obj.PrintLaTeX(mult) << std::endl  << obj5.PrintMathML(mult) << std::endl;
        std::cout << obj2.PrintLaTeX(add) << std::endl  << obj6.PrintMathML(add) << std::endl;
        std::cout << obj3.PrintLaTeX(sub) << std::endl  << obj7.PrintMathML(sub) << std::endl;
        std::cout << obj4.PrintLaTeX(div2) << std::endl  << obj8.PrintMathML(div2) << std::endl;
        std::cout << obj10.PrintLaTeX(pow) << std::endl  << obj9.PrintMathML(pow) << std::endl;
	std::cout << obj11.PrintLaTeX(secondTest) << std::endl << obj12.PrintMathML(secondTest) << std::endl;
	delete secondTest;
	delete div2;
    return 0;
}
