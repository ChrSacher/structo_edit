#ifndef ELEMENT_H
#define ELEMENT_H

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
	virtual std::shared_ptr<Element>& getNext() { return __after; }

	/**
	* @brief get element before the element in the structogram chain
	*
	* @return reference to shared ptr for mutliple use of the object
	*/
	const std::shared_ptr<Element>& getBefore() const { return __before; }

	/**
	* @brief get element after the element in the structogram chain
	*
	* @return reference to shared ptr for multiple use of the element
	*/
	const std::shared_ptr<Element>& getAfter() const  { return __after; }


	/**
	* @brief execute the element with the logik in it
	*
	* This method will execute the logik implemented in the element.
	* It will update the variables in the structogram and return the next element in the
	* chain.
	*
	* @param variables variables within the structogramm - MAY BE CHANGED
	*/
	virtual std::shared_ptr<Element>& execute(VariableMap& variables) = 0;

	/**
	* @brief Does nothing, since shared_ptr will do all the deleting and reference counting
	*/
	virtual ~Element () {}



protected:
	std::shared_ptr<Element>	__before; 	/**< The element before the structogram */
	std::shared_ptr<Element>	__after;	/**< The element after the structogram */
	
	std::string					__text;		/**< Text displayed on the node in the gui */
};


#endif /* end of include guard: ELEMENT_H */
