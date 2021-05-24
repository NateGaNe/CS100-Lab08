#ifndef VISITMATHML_H
#define VISITMATHML_H

#include "visitor.hpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

class VisitMathML : public Visitor{
	public:
		virtual void visit_op(Op* node) { outputString += "<cn>" + node->stringify() + "</cn>"; }
        	virtual void visit_rand(Rand* node)  { outputString += "<cn>" + node->stringify() + "</cn>"; }
		virtual void visit_add_begin(Add* node) { outputString += "<apply>\n" + indent + "  <plus/>\n";}
        	virtual void visit_add_middle(Add* node) { outputString += "\n"; }
        	virtual void visit_add_end(Add* node) { outputString += "</apply>\n"; }
        	virtual void visit_sub_begin(Sub* node) { outputString += "<apply>\n"+ indent + "  <minus/>\n"; }
        	virtual void visit_sub_middle(Sub* node) { outputString += "\n"; }
        	virtual void visit_sub_end(Sub* node) { outputString += "</apply>\n"; }
        	virtual void visit_mult_begin(Mult* node) { outputString += "<apply>\n" + indent + "  <times/>\n"; }
        	virtual void visit_mult_middle(Mult* node) { outputString += "\n"; }
        	virtual void visit_mult_end(Mult* node) { outputString += "</apply>\n"; }
        	virtual void visit_div_begin(Div* node) { outputString += "<apply>\n" + indent + "  <divide/>\n"; }
        	virtual void visit_div_middle(Div* node) { outputString += "\n"; }
        	virtual void visit_div_end(Div* node) { outputString += "</apply>\n"; }
        	virtual void visit_pow_begin(Pow* node) { outputString += "<apply>\n" + indent + "  <power/>\n"; }
        	virtual void visit_pow_middle(Pow* node) { outputString += "\n"; }
        	virtual void visit_pow_end(Pow* node) { outputString += "</apply>\n"; }
		std::string PrintMathML(Base* ptr){
			outputString += "<math>\n";
			Iterator iteration(ptr);
			int count = 1;
			while(!iteration.is_done()){
				if(iteration.current_index() != 3){
					count++;
				}
				
				printIndet(count);
				outputString += indent;
				iteration.current_node()->accept(this, iteration.current_index());
				if(iteration.current_index() == 3){
					count = count - 1;
				}
				iteration.next();
			}
			outputString += "</math>";
			return outputString;
		}
	private:
		std::string outputString;
		std::string indent;	
		void printIndet(int count){
			indent = "";
			for(int i = 0; i < count; i++){
				indent += "  ";
			}
		}
};
#endif
