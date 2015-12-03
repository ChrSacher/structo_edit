#ifndef STRUCTOGRAM_H
#define STRUCTOGRAM_H

#include "Element.h"
#include "VariableMap.h"

#include "Sequenz.h"

#include <vector>
#include <string>

#include <memory>


class Structogram 
{
public:
	/**
	* @brief Default construction with a name if necessary
	*
	* @param name of structogram in gui
	*/
	Structogram (const std::string& name = "structogram1");


	virtual ~Structogram () {}


	/**
	* @brief returns the last logical element of the structogram (last in gui)
	*
	* @return last element of structogram, logical
	*/
	std::shared_ptr<Element> getLastLogicalElement();


	/**
	* @brief get name of the structogram
	*
	* @return name of the structogram
	*/
	const std::string& getName() const { return __name; }
	

	/**
	* @brief set new name for the structogram
	*
	* @param name new name for the structogram
	*/
	void setName(const std::string& name) { __name = name; }


	/**
	* @brief append sequenz with text written on it
	*
	* @param text written on the sequenz
	*/
	void appendSequenz(const std::string& text);


	/**
	* @brief logicBlock -> True --> sequenz in if, False --> After
	*
	* @param condition
	*/
	void appendIf(const std::string& condition) {}


	/**
	* @brief logicBlock -> True --> sequenz in if, False --> Sequenz in False block
	*
	* @param condition
	*/
	void appendIfElse(const std::string& condition) {}


	/**
	* @brief logicBlock -> True -> Sequenz, always append goto to (self), false -> block after
	*
	* @param condition
	*/
	void appendWhile(const std::string& condition) {}


	/**
	* @brief all variables within the structogram
	*
	* not needed right now, since we dont want execution at this state.
	*/
	VariableMap								variables;


	friend void debug(const Structogram& s);

private:
	/**
	* @brief Contains all elements saved in the structogram, not for iterating
	*/
	std::vector<std::shared_ptr<Element> >	__elements;


	std::string								__name; /**< name of the structogram in the gui */

};



/**
* @brief output debugging output for the structogram
*
* @param s structogram to output
*/
void debug(const Structogram& s);


#endif /* end of include guard: STRUCTOGRAM_H */
