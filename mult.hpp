#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"

class Mult : public Base {
    public:
	Mult(Base* firstOp, Base* secondOp) : Base() {
		firstn = firstOp->evaluate();
		secondn = secondOp->evaluate();
		firsts = firstOp->stringify();
		seconds = secondOp->stringify();
		delete firstOp;
		delete secondOp;	
	}
	virtual double evaluate(){
		return firstn * secondn;
	}
	virtual std::string stringify(){
		std::string temp = "(" + firsts + ") * (" +seconds + ")";
		return temp;
	}
   private:
	double firstn;
	double secondn;
	std::string firsts;
	std::string seconds;
};

#endif //__MULT_HPP__
