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


void Element::insertBefore(std::shared_ptr<Element>& element)
{
	// connect new element with my before element
	element->__before = this->__before;

	// connect new element with myself
	element->__after.reset(this);

	// connect me with new element
	this->__before = element;
}


void Element::insertAfter(std::shared_ptr<Element>& element)
{
	// connect new element with my after element
	element->__after = this->__after;

	// connect new element with myself
	element->__before.reset(this);

	// connect me with new element
	this->__after = element;
}


void Element::deleteBefore()
{
	__before.reset();
}


void Element::deleteAfter()
{
	__after.reset();
}


void debug(std::shared_ptr<Element>& element)
{
	std::stringstream ss;
	ss << "Element @" << element << std::endl;
	ss << "\tBefore: @" << element->getBefore() << "\t - After: @" << element->getAfter() << std::endl;

	std::cout << ss.str();
}




