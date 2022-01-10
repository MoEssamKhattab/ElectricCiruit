#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection 
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
	bool selected = false;
	string m_labelc;
public:
	Connection(GraphicsInfo* r_GfxInfo1, Component *cmp1=nullptr, Component *cmp2=nullptr);
	GraphicsInfo* getConctsInfo();
	virtual void Draw(UI* );	//for connection to Draw itself
	
	bool getSelected();
	void setSelected(bool sel);
	//virtual string getlabelc();
	//virtual void setlabelc(string sel);

	virtual void save(ofstream& savefile);
	virtual void load(ifstream& loadfile);
};
