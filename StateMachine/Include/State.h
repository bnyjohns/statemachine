#pragma once
#include "Transition.h"

#include <map>
#include <memory>
#include <unordered_set>

using namespace std;

class State
{
protected:
	vector<Transition> transitions;
public:
	StateEnum state;
	virtual StateEnum Next(Event event)
	{
		auto transitionIt = find_if(transitions.begin(), transitions.end(), [event](const Transition& t) {
			return t.m_event == event;
		});

		if (transitionIt == transitions.end())
			return StateEnum::Invalid;

		return (*transitionIt).to;
	}
};

class InActiveState : public State
{
public:
	InActiveState()
	{
		state = StateEnum::InActive;
		transitions.push_back(Transition(Event::Begin, StateEnum::Active));
		transitions.push_back(Transition(Event::Exit, StateEnum::Exited));
	}
};

class ActiveState : public State
{
public:
	ActiveState()
	{
		state = StateEnum::Active;
		transitions.push_back(Transition(Event::End, StateEnum::InActive));
		transitions.push_back(Transition(Event::Pause, StateEnum::Paused));
	}
};

class PausedState : public State
{
public:
	PausedState()
	{
		state = StateEnum::Paused;
		transitions.push_back(Transition(Event::Resume, StateEnum::Active));
		transitions.push_back(Transition(Event::End, StateEnum::InActive));
	}
};

class ExitedState : public State
{
public:
	ExitedState()
	{
		state = StateEnum::Exited;
	}
};
