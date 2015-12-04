#ifndef SEQUENZ_H
#define SEQUENZ_H

#include "Element.h"

/**
* @brief Sequenz is the most basic element of a structogram -> pretty much the same as 
* the element itself
*/
class Sequenz : public Element 
{
public:
	Sequenz (const std::string& text) : Element() {setText(text); }
	Sequenz (Element* before, Element* after = nullptr) : Element(before, after) {}
	Sequenz (std::shared_ptr<Element>& before) : Element(before) {}
	Sequenz (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after) : Element(before, after) {}

	virtual ~Sequenz () {}

private:

};


#endif /* end of include guard: SEQUENZ_H */
