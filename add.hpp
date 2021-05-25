#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "op.hpp"
using namespace std;
class Add : public Base{
	public:
		Add(Base* firstNum, Base* secondNum) : Base(firstNum, secondNum) {
			firstString = firstNum -> stringify();
			secondString = secondNum -> stringify();
			firstNumber = firstNum -> evaluate();
			secondNumber = secondNum -> evaluate();
		}
		virtual ~Add() {
			delete left;	
			delete right;
		}	
                virtual string stringify() {
                        string temp2 = "(" + firstString + ") + ("  + secondString + ")";
                        return temp2;
		}

		virtual double evaluate(){
			double temp = firstNumber + secondNumber;
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
				visitor->visit_add_begin(this);
			}
			else if(index == 1){
				visitor->visit_add_middle(this);
			}
			else if(index == 2){
				visitor->visit_add_end(this);
			}
		}	
	private:
		double firstNumber;
		double secondNumber;
		string firstString;
		string secondString;
	};
#endif
