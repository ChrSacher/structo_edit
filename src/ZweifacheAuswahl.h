#ifndef EINFACHE_AUSWAHL_H
#define EINFACHE_AUSWAHL_H

#include "Element.h"

class ZweifacheAuswahl 
{
public:
	ZweifacheAuswahl ();
	ZweifacheAuswahl (Element* before, Element* after = nullptr);
	ZweifacheAuswahl (std::shared_ptr<Element>& before);
	ZweifacheAuswahl (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VaribaleMap& variables);

	virtual ~ZweifacheAuswahl ();

private:
	
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
