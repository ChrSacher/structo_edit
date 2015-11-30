


class Element {
	
	Element* execute()
	{
		evaluate();
		run();

		return getNext()
		
	}
	virtual Element* getNext();

	Element* 	__davor; // NULL bei start
	Element* 	__danach; // NULL bei ende
}



class LogicElement : public Element
{
	Element* getNext()
	{
		if(evaluate())
			return __on_true;
		else
			return __on_false;
	}
	Element* 	__on_true;
	Element*	__on_false;
}


class GotoElement : public Element
{
	Element* getNext()
	{
		return __goto;
	}

	Element*	__goto;
}


void add_while()
{
	Listenposi.add(LogicElement)
	Listenposi.add(GotoElement)
}


void visualize(Element* e)
{
	
}
