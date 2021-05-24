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
    Base* mult = new Mult(seven, three);
	VisitorLaTeX obj;
	VisitMathML obj2;
	std::cout << obj.PrintLaTeX(mult) << std::endl  << obj2.PrintMathML(mult) << std::endl;
	delete mult;
    return 0;
}
