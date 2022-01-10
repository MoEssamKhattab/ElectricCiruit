#pragma once

#include "action.h"

//Class responsible for adding a new Buzzer action
class ActionCopy : public Action
{
private:
	int x, y;
	int xp, yp;
	
public:
	
	ActionCopy(ApplicationManager* pApp);
	virtual ~ActionCopy(void);
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};