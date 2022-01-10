#pragma once

#include "action.h"

//Class responsible for adding a new Buzzer action
class ActionLabel : public Action
{
private:
	int x, y;
	
public:
	ActionLabel(ApplicationManager* pApp);
	virtual ~ActionLabel(void);
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};