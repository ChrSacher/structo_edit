#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class EndlosSchleife 
{
public:
	EndlosSchleife ();
	EndlosSchleife (Element* before, Element* after = nullptr);
	EndlosSchleife (std::shared_ptr<Element>& before);
	EndlosSchleife (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~EndlosSchleife ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
