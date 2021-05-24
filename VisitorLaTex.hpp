#ifndef VISITORLATEX_HPP
#define VISITORLATEX_HPP
#include "visitor.hpp"

class VisitorLaTeX public:Visitor {
public:
	std::string PrintLaTeX(Base* ptr) {
		outputString += "$";
		Iterator iteration(ptr);
		while (!iteration.is_done()){
			iteration.current_node()->accept(this,iteration.current_index());
			iteration.next();
		{
		outputString += "$";
		return outputString;
	}
	virtual void visit_op(Op* node) (outputString += "{" + node->stringify() + "}";}
	virtual void visit_rand(Rand* node) {outputString += "{" + node->stringify() + "}";}
        virtual void visit_add_begin(Add* node){outputString += "(";}
        virtual void visit_add_middle(Add* node) {outputString += "+";}
        virtual void visit_add_end(Add* node){outputString += ")";}
        virtual void visit_sub_begin(Sub* node){outputString += "(";}
        virtual void visit_sub_middle(Sub* node){outputString += "-";}
        virtual void visit_sub_end(Sub* node){outputString += ")";}
        virtual void visit_mult_begin(Mult* node){outputString += "(";}
        virtual void visit_mult_middle(Mult* node){outputString += "\cdot";}
        virtual void visit_mult_end(Mult* node){outputString += ")";}
        virtual void visit_div_begin(Div* node){outputString += "\frac{";}
        virtual void visit_div_middle(Div* node){outputString += "}{";}
        virtual void visit_div_end(Div* node){outputString += "}";}
        virtual void visit_pow_begin(Pow* node){outputString += "(";}
        virtual void visit_pow_middle(Pow* node){outputString += "^";}
        virtual void visit_pow_end(Pow* node){outputString += ")";}
private:
	std::string outputString;

};
#endif
