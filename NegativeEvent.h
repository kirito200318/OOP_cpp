#ifndef NEGATIVEEVENT_H
#define NEGATIVEEVENT_H
#include "GameEvent.h"
class NegativeEvent : public GameEvent {
public:
	GameEvent* Clone() override;
	void ApplyEvent(Hero& hero, Controller& controller) override;
};

#endif