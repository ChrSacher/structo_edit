#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class Fallauswahl 
{
public:
	Fallauswahl ();
	Fallauswahl (Element* before, Element* after = nullptr);
	Fallauswahl (std::shared_ptr<Element>& before);
	Fallauswahl (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~Fallauswahl ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
