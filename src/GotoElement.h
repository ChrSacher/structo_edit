#ifndef GOTO_ELEMENT_H
#define GOTO_ELEMENT_H


#include "Element.h"

class GotoElement 
{
public:
	GotoElement (std::shared_ptr<Element>& jump_to) : 
		Element{},
		__jump_mark{jump_to}
	{

	}


	virtual ~GotoElement () {}


	/**
	* @brief Always jump to jump_mark
	*
	* @param variables
	*
	* @return 
	*/
	virtual std::shared_ptr<Element> execute(Variable& variables)
	{
		return __jump_mark;
	}

private:
	std::shared_ptr<Element>	__jump_mark;
};


#endif /* end of include guard: GOTO_ELEMENT_H */
