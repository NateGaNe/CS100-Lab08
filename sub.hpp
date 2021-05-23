#ifndef __SUB_HPP__
#define __SUB_HPP__
#include "op.hpp"
using namespace std;
class Sub : public Base{
        public:
                Sub(Base* firstNum, Base* secondNum) : Base() {
                        firstString = firstNum -> stringify();
                        secondString = secondNum -> stringify();
                        firstNumber = firstNum -> evaluate();
                        secondNumber = secondNum -> evaluate();
			delete firstNum;
			delete secondNum;
                }
                virtual string stringify() {
                        string temp2 = "(" + firstString + ") - ("  + secondString + ")";
                        return temp2;
                }

                virtual double evaluate(){
                        double temp = firstNumber - secondNumber;
                        return temp;
                }

        private:
                double firstNumber;
                double secondNumber;
                string firstString;
                string secondString;
        };
#endif

