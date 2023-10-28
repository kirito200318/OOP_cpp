#pragma once
#include "GameEvent.h"
class PositiveEvent : public GameEvent {
public:
	GameEvent* Clone() override;
	void ApplyEvent(Hero& hero, Controller& controller) override;
};

