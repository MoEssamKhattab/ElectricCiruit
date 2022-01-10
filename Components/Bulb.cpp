#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	Ccount++;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass bulb drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo,selected); //update to draw bulb

}

Component* Bulb::createcopy()
{
	Component* Copycomp = new Bulb(m_pGfxInfo);
	return Copycomp;
}
//void Resistor::setlabel(string label)
//{
//	m_Label = label;
//}
//string Resistor::getlabel()
//{
//	return m_Label;
//}


void Bulb::save(ofstream& savefile)
{
	savefile << "BLB\t" << id << "\tLabel\t" << value << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y << endl;
}

void Bulb::load(ifstream& loadfile)
{

}

void Bulb::Operate()
{

}