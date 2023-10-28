#pragma once
#include "GameEvent.h"
class NegativeEvent : public GameEvent {
public:
	GameEvent* Clone() override;
	void ApplyEvent(Hero& hero, Controller& controller) override;
};

