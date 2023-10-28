#pragma once
#include "GameEvent.h"
class MoveToStart : public GameEvent {
public:
	GameEvent* Clone() override;
	void ApplyEvent(Hero& hero, Controller& controller) override;
};
