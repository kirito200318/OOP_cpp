#pragma once
#include "NegativeEvent.h"
GameEvent* NegativeEvent::Clone() {
	return new NegativeEvent();
}

void NegativeEvent::ApplyEvent(Hero& hero, Controller& controller) {
	hero.setHP(hero.getHP() - 5);
	hero.setCP(hero.getCP() - 5);
	hero.setMana(hero.getMana() - 5);
}
