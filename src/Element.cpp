#include "Element.h"

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


