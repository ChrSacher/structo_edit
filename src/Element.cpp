#include "Element.h"
#include <sstream>
#include <iostream>

Element::Element() :
	__before{ nullptr },
	__after{ nullptr }
{

}


Element::Element(Element* before, Element* after) :
	__before{ before },
	__after{ after }
{

}


Element::Element(std::shared_ptr<Element>& before) :
	__before{ before },
	__after{ nullptr }
{

}


Element::Element(std::shared_ptr<Element>& before, std::shared_ptr<Element>& after) :
	__before{ before },
	__after{ after }
{

}


void Element::insertBefore(std::shared_ptr<Element> element)
{
	// connect new element with my before element
	element->__before = this->__before;

	// connect new element with myself
	element->__after.reset(this);

	// connect current before element with element
	if(this->__before)
		this->__before->__after = element;

	// connect me with new element
	this->__before = element;
}


void Element::insertAfter(std::shared_ptr<Element> element)
{
	// connect new element with my after element
	element->__after = this->__after;
	std::cout << "element->__after = this->__after" << std::endl;

	// connect current after element with new element
	if(element->__after != nullptr)
	{
		std::cout << element->__after << std::endl;
		std::cout << element->__after->__before << std::endl;
		element->__after->__before = element;
	}
	std::cout << "element->__after->__before = element" << std::endl;

	// connect new element with myself
	element->__before.reset(this);
	std::cout << "element->__before.reset(this)" << std::endl;

	// connect me with new element
	this->__after = element;
	std::cout << "this->__after = element" << std::endl;
}


void Element::deleteBefore()
{
	__before.reset();
} 

void Element::deleteAfter()
{
	__after.reset();
}


void debug(const std::shared_ptr<Element>& element)
{
	std::stringstream ss;
	ss << "Element @" << element << std::endl;
	ss << "\tBefore: @" << element->getBefore() << "\t - After: @" << element->getAfter() << std::endl;
	ss << "\t" << element->getText() << std::endl;

	std::cout << ss.str();
}




