#ifndef LOGIC_BLOCK_H
#define LOGIC_BLOCK_H


#include "Element.h"
#include <string>
#include <memory>

class LogicBlock : Element
{
public:
	LogicBlock (const std::string& expression) :
		Element{},
		__logical_expression{expression},
		__next_on_true{ nullptr },
		__next_on_false{ nullptr }
	{ }

	virtual ~LogicBlock () {}

	/**
	* @brief evaluate logical expression and return the needed element in logic chain
	*
	* @param variables of the structogram -> has access to all variables
	*
	* @return shared_ptr to the next element depending on logic expression
	*/
	std::shared_ptr<Element> execute(VariableMap& variables);


	/**
	* @brief set element which should be executed on true evaluation of logic expression
	*
	* @param el
	*/
	void setNextOnTrue(const std::shared_ptr<Element>& el) { __next_on_true = el; }


	/**
	* @brief set element which should be executed on false evaluation of logic expression
	*
	* @param el
	*/
	void setNextOnFalse(const std::shared_ptr<Element>& el) { __next_on_false = el; }


	/**
	* @brief return the next element which should be executed on true evaluation of logic
	* expression
	*
	* @return 
	*/
	const std::shared_ptr<Element>& getNextOnTrue() const { return __next_on_true; }


	/**
	* @brief return the next element which sould be executed on false evaluation of logic
	* expression
	*
	* @return 
	*/
	const std::shared_ptr<Element>& getNextOnFalse() const { return __next_on_false; }


private:
	std::string					__logical_expression;


	std::shared_ptr<Element>	__next_on_true; /**< if logic expression is true, this
	element is next in the logic chain */
	std::shared_ptr<Element>	__next_on_false; /**< if logic expression is false, this element is next in the logic chain (else or skip) */
};



#endif /* end of include guard: LOGIC_BLOCK_H */
