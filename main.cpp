#include <iostream>

#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "op.hpp"
int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);
    Base* div = new Div(add, three);
    Base* rand = new Rand();
    Base* randMult = new Mult(rand, three);

        std::cout << randMult->stringify() << " = " << randMult->evaluate() << std::endl;	
    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
	Base* add2= new Add(three,seven);
	std::cout << add2->stringify() << " = " << add2->evaluate() << std::endl;
        Base* sub= new Sub(three,seven);
        std::cout << sub->stringify() << " = " << sub->evaluate() << std::endl;
        Base* pow= new Pow(three,seven);
        std::cout << pow->stringify() << " = " << pow->evaluate() << std::endl;
	
	std::cout << div->stringify() << " = " << div->evaluate() << std::endl;
	
    return 0;
}
