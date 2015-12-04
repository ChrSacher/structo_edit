#ifndef ZWEIFACHE_AUSWAHL_H 

#define ZWEIFACHE_AUSWAHL_H

#include "Element.h"

class ZweifacheAuswahl : public Element
{
public:
	ZweifacheAuswahl ();
	ZweifacheAuswahl (Element* before, Element* after = nullptr);
	ZweifacheAuswahl (std::shared_ptr<Element>& before);
	ZweifacheAuswahl (std::shared_ptr<Element>& before, std::shared_ptr<Element>& after);

	virtual std::shared_ptr<Element>& execute(VariableMap& variables);

	virtual ~ZweifacheAuswahl ();

private:
	
	std::shared_ptr<Element> __trueElement;
	std::shared_ptr<Element> __falseElement;
	std::string __condition;
	bool evaluated;
};


#endif /* end of include guard: EINFACHE_AUSWAHL_H */
