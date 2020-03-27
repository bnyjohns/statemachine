#include "StateMachine.h"

StateMachine::StateMachine()
{
	states[StateEnum::InActive] = make_shared<InActiveState>();
	states[StateEnum::Active] = make_shared<ActiveState>();
	states[StateEnum::Paused] = make_shared<PausedState>();
	states[StateEnum::Exited] = make_shared<ExitedState>();
}

StateMachine::~StateMachine()
{
	
}

void StateMachine::Initialize(StateEnum state)
{
	currentState = states[state];
}

void StateMachine::ProcessEvent(Event event)
{
	auto initialState = currentState->state;
	auto nextStateEnum = currentState->Next(event);
	if (states.find(nextStateEnum) != states.end())
	{
		currentState = states[nextStateEnum];
		cout << "Transition. From " << StateToStr(initialState) << " to " << StateToStr(currentState->state) << ". Event:" << EventToStr(event) << endl;
	}
	else
	{
		cout << "INVALID transition. From " << StateToStr(initialState) << ". Event:" << EventToStr(event) << endl;
	}
}

const char* StateMachine::StateToStr(StateEnum state)
{
	switch (state)
	{
		case StateEnum::Active: return "Active";
		case StateEnum::Exited: return "Exited";
		case StateEnum::InActive: return "InActive";
		case StateEnum::Invalid: return "Invalid";
		case StateEnum::Paused: return "Paused";
		default: return "UNRECOGNIZED";
	}
}

const char* StateMachine::EventToStr(Event event)
{
	switch (event)
	{
		case Event::Begin: return "Begin";
		case Event::End: return "End";
		case Event::Exit: return "Exit";
		case Event::Pause: return "Pause";
		case Event::Resume: return "Resume";
		default: return "UNRECOGNIZED";
	}
}