#pragma once

#include "action.h"

//Class responsible for adding a new Buzzer action
class ActionUnselect : public Action
{
private:
	int x, y;
	int xd, yd;
public:
	ActionUnselect(ApplicationManager* pApp);
	virtual ~ActionUnselect(void);
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};