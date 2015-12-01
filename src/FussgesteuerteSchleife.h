#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class FussgesteuerteSchleife 
{
public:
	FussgesteuerteSchleife ();
	FussgesteuerteSchleife (Element* before, Element* after = nullptr);
	FussgesteuerteSchleife (std::shared_ptr<Element>& before);
	FussgesteuerteSchleife (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~FussgesteuerteSchleife ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
