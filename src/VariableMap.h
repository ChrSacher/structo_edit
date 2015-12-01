#ifndef VARIABLEMAP_H
#define VARIABLEMAP_H


#include <map>
#include <utility>


enum StructogramType
{
	Boolean,	/**< will map to bool in c++ */
	String,		/**< will map to std::string in c++ */
	Integer,	/**< will map to int in c++ */
	Float,		/**< will map to double in c++ */
};


/**
* @brief Define the VariableMap for the structogram for internal use, will be save in
* a structogram
*
* Every Variable will be defined uniquely by its name within a structogram.
* It can have one of 4 types \sa StructogramType
* The string in the pair will save the representation of the Variable, with must be parsed
* 
* Boolean: -> True | False
* Integer: normal number -1 | 0 | 12023 | -120312309 | 92348 | but not 0012381234
* String: No Parsing Necessary
* Float: .123 | -0.123 | 123085 | 12934.12394 
*
* One Dimensional Arrays will be the normal representation but contained in [], seperated
* by semicola (;). Characters must be escaped in strings with \ (escape)
*/
typedef std::map<std::string, std::pair<enum StructogramType, std::string>> VariableMap;


// ------------
// Helper functions for the variable map
// ------------


#endif /* end of include guard: VARIABLEMAP_H */
