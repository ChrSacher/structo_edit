#include "VariableMap.h"
#include <stdexcept>
#include <sstream>

bool Variable::typeComp(StructogramType r, StructogramType b)
{
	if (r == b && r != Boolean) return true;
	if ((r == Float && b == Integer) || (b == Float && r == Integer)) return true;
	return true;
}
Variable Variable::operator+(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to add different Types or add boleans");
		return *this;
	}
	switch (__type)
	{	
		case String:
		{
			return Variable(String, __value + Other.__value);
		}; break;
		case Integer:
		{
			if(Other.__type == Integer) return Variable(Integer, std::to_string(std::stoi(__value) + std::stoi(Other.__value)));
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{
			return Variable(Float, std::to_string(std::stof(__value) + std::stof(Other.__value)));
		}; break;
	}
	
}
Variable Variable::operator-(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to add different Types or add boleans");
		return *this;

	}
	switch (__type)
	{
		case String:
		{
			std::string returnS = __value;
			std::string::size_type i;
			while ((i = returnS.find(Other.__value)))
			{
				if (i == std::string::npos) break;
				returnS.erase(i, Other.__value.length());
			}
			return Variable(String, returnS);
		}; break;
		case Integer:
		{
			if (Other.__type == Integer) return Variable(Integer, std::to_string(std::stoi(__value) - std::stoi(Other.__value)));
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{
			return Variable(Float, std::to_string(std::stof(__value) - std::stof(Other.__value)));
		}; break;
	}
}
Variable Variable::operator*(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to mul different Types or mul boleans");
		return *this;
	}
	switch (__type)
	{
		case String:
		{
			throw("Trying to mul Strings"); 
			return *this;
		}; break;
		case Integer:
		{
			if (Other.__type == Integer) return Variable(Integer, std::to_string(std::stoi(__value) * std::stoi(Other.__value)));
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{
			return Variable(Float, std::to_string(std::stof(__value) * std::stof(Other.__value)));
		}; break;
	}
}
Variable Variable::operator/(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to div different Types or div boleans");
		return *this;
	}
	switch (__type)
	{
		case String:
		{
			throw("Trying to div Strings");
			return *this;
		}; break;
		case Integer:
		{
			if (Other.__type == Integer) return Variable(Float, std::to_string((float)(std::stoi(__value) / (float)(std::stoi(Other.__value)))));
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{
			return Variable(Float, std::to_string(std::stof(__value) /  std::stof(Other.__value)));
		}; break;
	}
}

Variable& Variable::operator+=(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to add different Types or add boleans");
		return *this;
	}
	switch (__type)
	{
		case String:
		{
			__value += Other.__value;
			__type = String;
			return *this;
		}; break;
		case Integer:
		{
			if (Other.__type == Integer)
			{
				__value = std::to_string(std::stoi(__value) + std::stoi(Other.__value));
				__type = Integer;
				return *this;
			}
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{	__value = std::to_string(std::stof(__value) + std::stof(Other.__value));
			return *this;
		}; break;
	}
	return *this;
}
Variable& Variable::operator-=(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to add different Types or add boleans");
		return *this;
	}
	switch (__type)
	{
		case String:
		{
			std::string::size_type i;
			while ((i = __value.find(Other.__value)) != std::string::npos)
			{
				__value.erase(i, Other.__value.length());
			}
			return *this;
		}; break;
		case Integer:
		{
			if (Other.__type == Integer)
			{
				__value = std::to_string(std::stoi(__value) - std::stoi(Other.__value));
				__type = Integer;
				return *this;
			}
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{	__value = std::to_string(std::stof(__value) - std::stof(Other.__value));
		return *this;
		}; break;
	}
	return *this;
}
Variable& Variable::operator*=(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to mul different Types or mul boleans");
		return *this;
	}
	switch (__type)
	{
		case String:
		{
			throw("Trying to *= Strings");
			return *this;
		}; break;
		case Integer:
		{
			if (Other.__type == Integer)
			{
				__value = std::to_string(std::stoi(__value) * std::stoi(Other.__value));
				__type = Integer;
			};
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{
			__type = Float;
			__value = std::to_string(std::stof(__value) * std::stof(Other.__value));
			return *this;
		}; break;
	}
	return *this;
}
Variable& Variable::operator/=(const Variable& Other)
{
	if (!typeComp(__type, Other.__type))
	{
		throw("Trying to div different Types or div boleans");
		return *this;
	}
	switch (__type)
	{
		case String:
		{
			throw("Trying to div Strings");
			return *this;

		}; break;
		case Integer:
		{
			if (Other.__type == Integer)
			{
				__value = std::to_string(std::stoi(__value) / std::stoi(Other.__value));
				__type = Integer;
			};
		}; //use Fallthrough since Integer and Float behaves like float + float
		case Float:
		{
			__type = Float;
			__value = std::to_string(std::stof(__value) / std::stof(Other.__value));
			return *this;
		}; break;
	}
}

bool Variable::operator==(const Variable& Other)
{
	if (__type == Other.__type)
	{
		return __value == Other.__value;
	}
	if ((__type == Float && Other.__type == Integer) || (__type == Integer && Other.__type == Float))
	{
		return std::stof(__value) == std::stof(Other.__value);
	}
	return false;
}
bool Variable::operator!=(const Variable& Other)
{
	return !(__type == Other.__type);
}

std::string Variable::getDebug()
{
	std::string returnString = "";
	returnString = get_type_str(__type) + " = " + returnString + __value + "\n";
	return returnString;
}

void Variable::setValue(const std::string& Value)
{
	__value = Value;
}
void Variable::setType(const StructogramType type)
{
	__type = type;
}

std::string Variable::getValue() const
{
	return __value;
}
StructogramType Variable::getType() const
{
	return __type;
}

bool VariableMap::exists(const std::string& varname)
{
	// true, when find(varname) is not __data::end() which it will be if it is not found
	return __data.find(varname) != __data.end();
}


Variable VariableMap::getVariable(const std::string& 
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
		__data[varname] = Variable(type, value);

		return;
	}

	// check for correct type, throw exeption if missmatched
	else
	{
		// will check only basetype, not on array and so on
		if (__data[varname].getType() == type)
		{
			// is not right, arrays and so an need special care
			__data[varname].setValue(value);
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
		ss << it->second.getValue() << std::endl;
	}

	std::cout << ss.str() << std::endl;
}


std::string get_type_str(const Variable &variable)
{
	StructogramType r = variable.getType();
	return get_type_str(r);
}

std::string get_type_str(StructogramType type)
{
	switch (type)
	{
		case Boolean:	return std::string("Boolean"); break;
		case String:	return std::string("String"); break;
		case Integer:	return std::string("Integer"); break;
		case Float:		return std::string("Float"); break;
		default:		return std::string("Invalid Type!"); break;
	}
}


