#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include "base.hpp"

class Div : public Base {
    public:
	Div(Base* firstOp, Base* secondOp) : Base() {
		firstn = firstOp->evaluate();
		secondn = secondOp->evaluate();
		firsts = firstOp->stringify();
		seconds = secondOp->stringify();
		delete firstOp;
		delete secondOp;
	}
	
	virtual double evaluate(){
		return firstn / secondn;
	}
	
	virtual std::string stringify(){
		std::string temp = "(" + firsts + ") / (" + seconds + ")";
		return temp;
	}
    private:
	double firstn;
	double secondn;
	std::string firsts;
	std::string seconds;
};

#endif //__DIV_HPP__
