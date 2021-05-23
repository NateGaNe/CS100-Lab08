#ifndef __POW_HPP__
#define __POW_HPP__
#include "op.hpp"
#include <cmath>
using namespace std;
class Pow : public Base{
        public:
                Pow(Base* firstNum, Base* secondNum) : Base() {
                        firstString = firstNum -> stringify();
                        secondString = secondNum -> stringify();
                        firstNumber = firstNum -> evaluate();
                        secondNumber = secondNum -> evaluate();
			delete firstNum;
			delete secondNum;
                }
                virtual string stringify() {
                        string temp2 = "(" + firstString + ") ** ("  + secondString + ")";
                        return temp2;
                }

                virtual double evaluate(){
                        double temp = pow(firstNumber,secondNumber);
                        return temp;
                }

        private:
                double firstNumber;
                double secondNumber;
                string firstString;
                string secondString;
        };
#endif

