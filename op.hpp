#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double inp) : Base() {value = inp; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
    private:
	double value;
};

#endif //__OP_HPP__
