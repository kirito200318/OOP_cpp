#pragma once
#include "MoveToStart.h"
GameEvent* MoveToStart::Clone() {
	return new MoveToStart();
}

void MoveToStart::ApplyEvent(Hero& hero, Controller& controller) {
	controller.set_coord(controller.get_field().getStartPosition());
}
