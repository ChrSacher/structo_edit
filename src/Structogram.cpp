#include "Structogram.h"
#include <iostream>

Structogram::Structogram(const std::string& name) :
	__name{ name }
{
	// always create root element
	// we can build our structogram from this
	__elements.push_back(std::shared_ptr<Element>{});
}


void Structogram::appendSequenz(const std::string& text)
{
	__elements.back()->insertAfter(std::shared_ptr<Element>(new Sequenz(text)));
}


void debug(const Structogram& s)
{
	std::cout << "Structogram: " << s.getName() << std::endl;
	
	auto element_to_print = s.__elements[0];

	do
	{
		debug(element_to_print);
		std::cout << std::endl;
	} while(element_to_print = element_to_print->getAfter());
}
