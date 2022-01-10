#include "Resistor.h"

Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{
	Ccount++;
}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,selected); //update to draw resistor

}

Component* Resistor::createcopy()
{
	Component* Copycomp = new Resistor(m_pGfxInfo);
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

void Resistor::Operate()
{

}




void Resistor::save(ofstream& savefile)
{
	savefile << "RES" << "\t" << id << "\tLabel\t" << value << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y << endl;
}
void Resistor::load(ifstream& loadfile)
{
}


 