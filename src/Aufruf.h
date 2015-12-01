#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class EinfacheAuswahl 
{
public:
	EinfacheAuswahl ();
	EinfacheAuswahl (Element* before, Element* after = nullptr);
	EinfacheAuswahl (std::shared_ptr<Element>& before);
	EinfacheAuswahl (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~EinfacheAuswahl ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
