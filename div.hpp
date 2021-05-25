#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include "base.hpp"

class Div : public Base {
    public:
	Div(Base* firstOp, Base* secondOp) : Base(firstOp, secondOp) {

		firstn = firstOp->evaluate();
		secondn = secondOp->evaluate();
		firsts = firstOp->stringify();
		seconds = secondOp->stringify();
	}

        virtual ~Div() {
       		 delete left;
                 delete right;
        }

	
	virtual double evaluate(){
		return firstn / secondn;
	}
	
	virtual std::string stringify(){
		std::string temp = "(" + firsts + ") / (" + seconds + ")";
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
		if(index == 0){
			visitor->visit_div_begin(this);
		}
		else if(index == 1){
			visitor->visit_div_middle(this);
		}
		else if(index == 2){
			visitor->visit_div_end(this);
		}
	}

    private:
	double firstn;
	double secondn;
	std::string firsts;
	std::string seconds;
};

#endif //__DIV_HPP__
