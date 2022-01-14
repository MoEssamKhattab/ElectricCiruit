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
	enum { MaxActCount = 100 };
	
private:
	int CompCount;		//Actual number of Components 
	int ConCount;
	int brashcount;
	int groundcount;

	

	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConList[MaxConCount];

	UI* pUI; //pointer to the UI
	
	ActionType ActType;
	
	int ActionCount, UndoCount, RedoCount;

	Action* UndoList[MaxActCount];
	Action* RedoList[MaxActCount];

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
	Component* Copycomponent(Component* comp, int xp, int yp);
	Connection* GetConList();

	int GetCompCount();
	int GetSelectedCompNum();

	int GetConCount();
	int GetSelectedConNum();

	bool CheckDrawingArea(int x, int y);

	Component* ApplicationManager::GetCompByID(int x);
	//Component* SDelete(Component* pC);

	bool componentconic(Component* comp);
	void fullyconnectedcheck();
	void deleteconnection(Component* comp);
	bool groundcheck();
	//bool noparallelcheck(Component* comp);
	void Addground();

	void unselect();
	
	void UpdateCompID();
	
	void Delete1(Component* pC);
	//void SDeleteCon(Connection* pC);
	void Delete();
	void DeleteMultCon();
	void DeleteCon(Connection* pC);

	
	void Exit(string);
	void Save(ofstream& savefile);
	void Load(ifstream& loadfile);

	void UpdateUndoAction(Action* pAction, int x);
	void UpdateRedoAction(Action* pAction, int x);

	void Undo();
	void Redo();

	int GetUndoCount() const;
	int GetRedoCount() const;

	//destructor
	~ApplicationManager();
};

#endif