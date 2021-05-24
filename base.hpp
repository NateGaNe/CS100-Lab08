#ifndef __BASE_HPP__
#define __BASE_HPP__
#include "visitor.hpp"
#include <string>

class Base {
    public:
        /* Constructors */
        Base(left, right) {
		this->left = left;
		this->right = right;
	}


        virtual ~Base() {}
    
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;

	virtual int number_of_children();
	virtual Base* get_child(int i);
   protected:
	Base* left;
	Base* right;
};

#endif //__BASE_HPP__
