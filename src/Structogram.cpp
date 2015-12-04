#include "Structogram.h"
#include <iostream>

Structogram::Structogram(const std::string& name) :
	__name{ name }
{
	// always create root element
	// we can build our structogram from this
	std::shared_ptr<Element> root{new Element};
	root->setText("Root Element");

	__elements.push_back(root);
	std::cout << root << std::endl;
}


std::shared_ptr<Element> Structogram::getLastLogicalElement()
{
	// last logical element has nullptr a after element -> we look for this
	// the root is always __elements[0] -> see structogram construction
	std::shared_ptr<Element> next = __elements[0];
	
	while(next->getAfter() != nullptr)
	{
		std::cout << "Next " << next->getAfter() << std::endl; 
		next = next->getAfter();
	}

	return next;
}


void Structogram::appendSequenz(const std::string& text)
{
	// create sequenz object
	std::shared_ptr<Element> seq{new Sequenz{text} };

	// create logical connection
	auto last = getLastLogicalElement();
	std::cout << "getLastLogicalElement()" << last << std::endl;

	last->insertAfter(seq);
	std::cout << "last->insertAfter()" << std::endl;

	// save this element in the elements vector
	__elements.push_back(seq);
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
