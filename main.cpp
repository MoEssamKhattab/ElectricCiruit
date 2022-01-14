
#include <iostream>
#include <sstream>
#include <cmath>
#include "ApplicationManager.h"

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	
		//cout <<"Undo" << AppManager.GetUndoCount() << endl;
		//cout << "Redo" << AppManager.GetRedoCount() << endl;
		//cout << "Comp" << AppManager.GetCompCount() << endl;

	}while(ActType != EXIT);
		
	return 0;
}

