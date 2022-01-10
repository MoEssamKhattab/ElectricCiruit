#pragma once
#include <iostream>
#include "action.h"
#include <fstream>
#include <string>

class ActionSave : public Action
{
private:

public:
	ActionSave(ApplicationManager* pApp);
	virtual ~ActionSave(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


