#ifndef ELEMENT_H
#define ELEMENT_H

/**
* @file This file implements the abstract interface of an element within a structogram.
*
* @author Jonas Toth
*/
#include <memory>
#include <string>
#include "VariableMap.h"


/**
* @brief Abstract class for every element in a structogram
*
* Gives basic functionality for every element within a structogram, but does not hold
* the structure for a Structogram. 
* The general idea is a linked list, with the links connecting the elements.
* Every structogram must contain such nodes and save them in an extra data structure.
*
* Create Element not on the Stack, since it will use smartpointers for its referencing.
* This class is only a helper for the structogramm, therefor the structogramm should take
* care of creating and keeping track of them.
*/
class Element 
{
public:
	/**
	* @brief default construction, the root of everything, will not contain any data
	*/
	Element ();


	/**
	* @brief construct element with existing connections, takes ownership of the pointers
	*
	* @param before element before, will take ownership of it
	* @param after element after, will take ownership of it
	*/
	Element (Element* before, Element* after = nullptr);


	/**
	* @brief construct element with connection to element before, rest is nullptr
	*
	* @param before element before, no ownership
	*/
	Element (std::shared_ptr<Element>& before);


	/**
	* @brief construct element with connections to before and after
	*
	* @param before element before, no ownership
	* @param after element after, no ownership
	*/
	Element (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);


	/**
	* @brief set the text which shall be displayed on the structoelement
	*
	* @param element_text text on the structoelement
	*/
	void setText(const std::string& element_text) { __text = element_text; }


	/**
	* @brief get the text of the element
	*
	* @return text as string
	*/
	const std::string& getText() const { return __text; }


	/**
	* @brief get the next element in the evaluation chain
	*
	* @return shared_ptr to next element
	*/
	virtual std::shared_ptr<Element> getNext() { return __after; }


	/**
	* @brief get element before the element in the structogram chain
	*
	* @return reference to shared ptr for mutliple use of the object
	*/
	std::shared_ptr<Element> getBefore() const { return __before; }


	/**
	* @brief get element after the element in the structogram chain
	*
	* @return reference to shared ptr for multiple use of the element
	*/
	std::shared_ptr<Element> getAfter() const  { return __after; }


	/**
	* @brief execute the element with the logik in it
	*
	* This method will execute the logik implemented in the element.
	* It will update the variables in the structogram and return the next element in the
	* chain.
	*
	* @param variables variables within the structogramm - MAY BE CHANGED
	*/
	virtual std::shared_ptr<Element> execute(VariableMap& variables) { return getAfter(); }


	/**
	* @brief Insert element before this one, NOT LOGICAL but hierarchical
	*
	* @param element which will be inserted
	*/
	void insertBefore(std::shared_ptr<Element> element);


	/**
	* @brief Insert element after this one, NOT LOGICAL but hierarchical
	*
	* @param element element which will be inserted
	*/
	void insertAfter(std::shared_ptr<Element> element);

	
	/**
	* @brief Delete element before -> only disconnect, no memory freeing
	*/
	void deleteBefore();


	/**
	* @brief Delete element after -> only disconnect, no memory freeing
	*/
	void deleteAfter();


	/**
	* @brief Does nothing, since shared_ptr will do all the deleting and reference counting
	*/
	virtual ~Element () {}



private:
	std::shared_ptr<Element>	__before; 	/**< The element before the structogram */
	std::shared_ptr<Element>	__after;	/**< The element after the structogram */

	std::string					__text;		/**< Text displayed on the node in the gui */
};


/**
* @brief print debugging output, like memory address of the element and so on
*
* @param element which will be outputted to stdout
*/
void debug(const Element& element);

memory* end of include guard: ELEMENT_H */
