#include "VariableMap.h"
#include <stdexcept>
#include <sstream>

bool VariableMap::exists(const std::string& varname)
{
	// true, when find(varname) is not __data::end() which it will be if it is not found
	return __data.find(varname) != __data::end();
}


std::pair<enum StructogramType, std::string> VariableMap::getValue(const std::string& 
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
