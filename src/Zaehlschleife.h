#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class Zaehlschleife 
{
public:
	Zaehlschleife ();
	Zaehlschleife (Element* before, Element* after = nullptr);
	Zaehlschleife (std::shared_ptr<Element>& before);
	Zaehlschleife (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~Zaehlschleife ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
