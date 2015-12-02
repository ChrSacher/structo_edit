#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class Aufruf 
{
public:
	Aufruf ();
	Aufruf (Element* before, Element* after = nullptr);
	Aufruf (std::shared_ptr<Element>& before);
	Aufruf (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~Aufruf ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
