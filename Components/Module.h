#pragma once
#include "Component.h"

class Module :public Component
{
	int R1 = 1; int R2 = 1; int R3 = 1; int R4 = 1;
	int R_eq = (((R1 + R2) * (R3 + R4)) / ((R1 + R2) + (R3 + R4)));
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Module

	void setR1(int);
	void setR2(int);
	void setR3(int);
	void setR4(int);


	int getR_eq();

	virtual void save(ofstream& savefile);
	virtual void load(ifstream& loadfile);
	virtual Component* createcopy();

};
