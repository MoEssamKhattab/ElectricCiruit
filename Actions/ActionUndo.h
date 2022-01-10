#pragma once
#include "action.h"


//Class responsible for Exit avtion
class ActionUndo : public Action
{


public:
	ActionUndo(ApplicationManager* pApp);
	virtual ~ActionUndo(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


