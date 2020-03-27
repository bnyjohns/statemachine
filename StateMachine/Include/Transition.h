#pragma once
#include "Event.h"
#include "StateEnum.h"

using namespace std;

class Transition
{
public:
	Event m_event;
	StateEnum to;
	Transition(const Event& event, const StateEnum& to): m_event(event), to(to)
	{
		
	}
	friend bool operator== (const Transition& t1, const Transition& t2)
	{
		return t1.m_event == t2.m_event;
	}
};
