#include "StateMachine.h"
using namespace std;

int main()
{
    auto stateMachine = make_shared<StateMachine>();
    stateMachine->Initialize(StateEnum::InActive);
    stateMachine->ProcessEvent(Event::Begin);
    stateMachine->ProcessEvent(Event::Pause);
    stateMachine->ProcessEvent(Event::Resume);
    stateMachine->ProcessEvent(Event::End);
    stateMachine->ProcessEvent(Event::End);
    stateMachine->ProcessEvent(Event::Exit);
}