#pragma once
#include "State.h"
#include "Event.h"
#include <iostream>

class StateMachine : enable_shared_from_this<StateMachine>
{
private:
	map<StateEnum, shared_ptr<State>> states;
	shared_ptr<State> currentState;
	const char* StateToStr(StateEnum state);
	const char* EventToStr(Event event);
public:
	void Initialize(StateEnum state);
	virtual void ProcessEvent(Event event);
	StateMachine();
	~StateMachine();
};