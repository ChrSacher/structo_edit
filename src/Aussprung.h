#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class Aussprung 
{
public:
	Aussprung ();
	Aussprung (Element* before, Element* after = nullptr);
	Aussprung (std::shared_ptr<Element>& before);
	Aussprung (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~Aussprung ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
