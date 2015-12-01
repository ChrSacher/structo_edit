#include "VariableMap.h"
#include <stdexcept>
#include <sstream>

bool VariableMap::exists(const std::string& varname)
{
	// true, when find(varname) is not __data::end() which it will be if it is not found
	return __data.find(varname) != __data.end();
}


std::pair<enum StructogramType, std::string> VariableMap::getVariable(const std::string& 
	varname)
{
	if (!exists(varname))
	{
		throw std::out_of_range("This variable does not exist!");
	}
	else
		return __data[varname];
}


void VariableMap::setValue(const std::string& varname, enum StructogramType type, const 
	std::string& value)
{
	// create the variable if not existing
	if (!exists(varname))
	{
		__data[varname] = std::pair<enum StructogramType, std::string> { type, value };

		return;
	}

	// check for correct type, throw exeption if missmatched
	else
	{
		// will check only basetype, not on array and so on
		if (__data[varname].first == type)
		{
			// is not right, arrays and so an need special care
			__data[varname].second = value;
		}
		else
		{
			std::stringstream error;
			error << "The type for the variable " << varname << " does not match!";
			throw std::invalid_argument(error.str());
		}
	}
}




// -----------------
// Helper Functions
// -----------------
void debug(const VariableMap& vm)
{
	std::stringstream ss;

	ss << "Variable Map my friend" << std::endl;

	for(auto it = vm.__data.begin(); it != vm.__data.end(); it++)
	{
		std::string type_str = get_type_str(it->second);

		ss << it->first;
		ss << " : ";
		ss << type_str << " = ";
		ss << it->second.second << std::endl;
	}

	std::cout << ss.str() << std::endl;
}


std::string get_type_str(const std::pair<enum StructogramType, std::string>& variable)
{
	switch(variable.first)
	{
		case Boolean:	return std::string("Boolean"); break;
		case String:	return std::string("String"); break;
		case Integer:	return std::string("Integer"); break;
		case Float:		return std::string("Float"); break;
		default:		return std::string("Invalid Type!"); break;
	}
}


