#pragma once
#include "Component.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Ground
	//virtual void setlabel(string label);
	//virtual string getlabel();

	virtual void save(ofstream& savefile);
	virtual void load(ifstream& loadfile);

	virtual Component* createcopy();
};