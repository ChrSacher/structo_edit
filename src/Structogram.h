#ifndef STRUCTOGRAM_H
#define STRUCTOGRAM_H

#include "Element.h"
#include "VaribaleMap.h"

#include <vector>


class Structogram 
{
public:
	Structogram ();
	virtual ~Structogram ();

private:
	/**
	* @brief Contains all elements saved in the structogram, not for iterating
	*/
	std::vector<std::shared_ptr<Element>>	__elements;

	VaribaleMap								__variables;

};


#endif /* end of include guard: STRUCTOGRAM_H */
