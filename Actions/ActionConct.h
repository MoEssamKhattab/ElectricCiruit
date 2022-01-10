#pragma once

#include "action.h"
#include "..\Components\Connection.h"

//Class responsible for adding a new resistor action
class ActionConct : public Action
{
private:
	int x1, x2, y1, y2;

public:
	ActionConct(ApplicationManager* pApp);
	virtual ~ActionConct(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};