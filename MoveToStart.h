#ifndef MOVETOSTART_H
#define MOVETOSTART_H
#include "GameEvent.h"
class MoveToStart : public GameEvent {
public:
	GameEvent* Clone() override;
	void ApplyEvent(Hero& hero, Controller& controller) override;
};

#endif
