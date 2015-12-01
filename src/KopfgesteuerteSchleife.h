#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class KopfgesteuerteSchleife 
{
public:
	KopfgesteuerteSchleife ();
	KopfgesteuerteSchleife (Element* before, Element* after = nullptr);
	KopfgesteuerteSchleife (std::shared_ptr<Element>& before);
	KopfgesteuerteSchleife (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~KopfgesteuerteSchleife ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
