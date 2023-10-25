#ifndef POSITIVEEVENT_CPP
#define POSITIVEEVENT_CPP
#include "PositiveEvent.h"
GameEvent* PositiveEvent::Clone() {
	return new PositiveEvent();
}

void PositiveEvent::ApplyEvent(Hero& hero, Controller& controller) {
	hero.setHP(hero.getHP() + 10);
	hero.setCP(hero.getCP() + 10);
	hero.setMana(hero.getMana() + 10);
}
#endif
