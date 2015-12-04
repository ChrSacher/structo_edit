#include "ZweifacheAuswahl.h"

bool evaluate(std::string r, VariableMap&){return true; };

ZweifacheAuswahl::ZweifacheAuswahl()
{
	evaluated = false;
}
ZweifacheAuswahl::~ZweifacheAuswahl()
{
}
std::shared_ptr<Element>& ZweifacheAuswahl::execute(VariableMap& variables)
{
	if (evaluated)
	{
		return __after;
		evaluated = false;
	}
	bool eval = evaluate(__condition,variables);
	evaluated = true;
	if (eval)
	{
		return __trueElement;
	}
	else
	{
		return __falseElement;
	}
}

//Idea is the inner loop is only connected to this Element
//Basically the last Element inside the if points back to this
//if this is run once the next time we get back to it we go over it and reset it
//if it is run twice and we go back to it (see while loop) we will evaluate again
//This also helps if the Ifs are nested since the stuff inside an If is only concerned with the if itself and not the entire structogram