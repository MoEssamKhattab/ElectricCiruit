#pragma once
#include "action.h"


//Class responsible for Exit avtion
class ActionExit : public Action
{


public:
	ActionExit(ApplicationManager* pApp);
	virtual ~ActionExit(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


