#ifndef VARIABLEMAP_H
#define VARIABLEMAP_H


#include <map>
#include <string>


enum StructogramType
{
	Boolean,	/**< will map to bool in c++ */
	String,		/**< will map to std::string in c++ */
	Integer,	/**< will map to int in c++ */
	Float,		/**< will map to double in c++ */
	Invalid
};

/**
* @brief Variable as an type which has many possible types \sa StructogramType
*/
class Variable
{
public:
	Variable(StructogramType Type, const std::string &Value) : __value(Value), __type(Type) {};
	Variable() :__value(""), __type(Invalid) {};
	Variable operator+(const Variable& Other);
	Variable operator-(const Variable& Other);
	Variable operator*(const Variable& Other);
	Variable operator/(const Variable& Other);
Variable& operator+=(const Variable& Other);
	Variable& operator-=(const Variable& Other);
	Variable& operator*=(const Variable& Other);
	Variable& operator/=(const Variable& Other);

	bool operator==(const Variable& Other);
	bool operator!=(const Variable& Other);

	std::string getDebug();
	bool typeComp(StructogramType r, StructogramType b);

	void setValue(const std::string& Value);
	void setType(const StructogramType type);

	std::string getValue() const;
	StructogramType getType() const;
private:
	std::string __value;
	StructogramType __type;
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
class VariableMap 
{
public:
	VariableMap () {}


	/**
	* @brief check if a variable exists in this variable map
	*
	* @param varname name of the variable 
	*
	* @return true if the variable exists, otherwise false
	*/
	bool exists(const std::string& varname);


	/**
	* @brief get the raw value of a variable
	*
	* will throw an out_of_range - execption if the variable does not exist
	*
	* @param varname name of the variable
	*
	* @return pair of datatype and raw value, which must be parsed
	*/
	Variable getVariable(const std::string& varname);

	
	/**
	* @brief set the value for a variable with the name 'varname'
	*
	* will create the variable if it does not exist yet
	* if the variable exists, but the type will not match, it throws an invalid_argument 
	* execption
	*
	* @param varname name of the variable which must be set
	* @param type type of the variable
	* @param value raw value of the variable, see type declaration
	*/
	void setValue(const std::string& varname, enum StructogramType type, const std::string& value);


	friend void debug(const VariableMap& vm);

private:
	std::map<std::string, Variable>	__data;
};


// ------------
// Helper functions for the variable map
// ------------
#include <iostream>
#include <sstream>

void debug(const VariableMap& vm);

std::string get_type_str(const Variable &var);
std::string get_type_str(StructogramType type);

#endif /* end of include guard: VARIABLEMAP_H */
