#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\ActionSave.h"

#include <fstream>
#include<sstream>


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200, MaxConCount = (MaxCompCount) * (MaxCompCount - 1) / 2};	//Max no of Components	

	
private:
	int CompCount;		//Actual number of Components 
	int ConCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConList[MaxConCount];

	UI* pUI; //pointer to the UI
	
	ActionType ActType;


public:
	friend void ActionSave::Execute();
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	Component* GetCompList();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	
	Component* componentcheck(int x, int y);
	Connection* connectioncheck(int x, int y);

	void AddConnection(Connection* pCon);
	void Copycomponent(Component* comp, int xp, int yp);

	void unselect();

	void Delete();
	void Exit(string);
	void Save(ofstream& savefile);
	void Load(ifstream& loadfile);
	//destructor
	~ApplicationManager();
};

#endif