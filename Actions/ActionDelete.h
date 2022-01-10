#pragma once
#include "action.h"


//Class responsible for Exit avtion
class ActionDelete : public Action
{


public:
	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


