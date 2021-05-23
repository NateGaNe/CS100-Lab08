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
	virtual int number_of_children(){
		int count = 0;
		if(left != nullptr){
			count += 1;
		}
		if(right != nullptr){
			count += 1;
		}
		return count;
        }
        virtual Base* get_child(int i){
                if(i == 0){
			return left;
		}
		else if(i == 1){
			return right;
		}
		return nullptr;
        }
        virtual void accept(Visitor* visitor, int index){
		if(index = 0){
                	visitor->visit_mult_begin(this);
               	}
                else if(index = 1){
                     	visitor->visit_mult_middle(this);
               	}
               	else if(index = 2){
                  	visitor->visit_mult_end(this);
                }
	}
   private:
	double firstn;
	double secondn;
	std::string firsts;
	std::string seconds;
};

#endif //__MULT_HPP__
