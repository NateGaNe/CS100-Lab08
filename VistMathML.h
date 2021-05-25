#ifndef VISITMATHML_H
#define VISITMATHML_H

#include "iterator.hpp"
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
		virtual void visit_op(Op* node) { outputString += "<cn>" + node->stringify() + "</cn>\n"; }
        	virtual void visit_rand(Rand* node)  { outputString += "<cn>" + node->stringify() + "</cn>\n"; }
		virtual void visit_add_begin(Add* node) { outputString += "<apply>\n" + indent + "  <plus/>\n";}
        	virtual void visit_add_middle(Add* node) {
                        count = count - 2;
                        printIndet();
                }
        	virtual void visit_add_end(Add* node) { outputString += "</apply>\n"; }
        	virtual void visit_sub_begin(Sub* node) { outputString += "<apply>\n"+ indent + "  <minus/>\n"; }
        	virtual void visit_sub_middle(Sub* node) { 
			count = count - 2;
			printIndet();
		}
        	virtual void visit_sub_end(Sub* node) { outputString += "</apply>\n"; }
        	virtual void visit_mult_begin(Mult* node) { outputString += "<apply>\n" + indent + "  <times/>\n"; }
        	virtual void visit_mult_middle(Mult* node) {
                        count = count - 2;
                        printIndet();
                }
        	virtual void visit_mult_end(Mult* node) { outputString += "</apply>\n"; }
        	virtual void visit_div_begin(Div* node) { outputString += "<apply>\n" + indent + "  <divide/>\n"; }
        	virtual void visit_div_middle(Div* node) {
                        count = count - 2;
                        printIndet();
                }
        	virtual void visit_div_end(Div* node) { outputString += "</apply>\n"; }
        	virtual void visit_pow_begin(Pow* node) { outputString += "<apply>\n" + indent + "  <power/>\n"; }
        	virtual void visit_pow_middle(Pow* node) {
                        count = count - 2;
                        printIndet();
                }
        	virtual void visit_pow_end(Pow* node) { outputString += "</apply>\n"; }
		std::string PrintMathML(Base* ptr){
			outputString += "<math>\n";
			Iterator iteration(ptr);
			while(!iteration.is_done()){
				if(iteration.current_index() != 2){
					count = count + 1;
					printIndet();
				}
				else if(iteration.current_index() == 2){
                                        count = count - 1;
                                	printIndet();
				}
				//printIdet(count);
				
				if(iteration.current_index() != 1){
					outputString += indent;
				}
				//outputString += indent;
				//outputString += "  ";
				iteration.current_node()->accept(this, iteration.current_index());
				//printIndet(count);
				//outputString += indent;
				iteration.next();
			}
			outputString += "</math>";
			return outputString;
		}
	private:
		int count = 0;
		std::string outputString;
		std::string indent;	
		void printIndet(){
			indent = "";
			for(int i = 0; i < count; i++){
				indent += "  ";
			}
		}
};
#endif
