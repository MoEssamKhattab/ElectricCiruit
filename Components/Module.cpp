#include "Module.h"

Module::Module(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	Ccount++;
}

void Module::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawModule(*m_pGfxInfo,selected); //update to draw resistor

}

void Module::setR1(int r1)
{
	R1 = r1;
}

void Module::setR2(int r2)
{
	R2 = r2;
}

void Module::setR3(int r3)
{
	R3 = r3;
}

void Module::setR4(int r4)
{
	R4 = r4;
}


int Module::getR_eq()
{
	return R_eq;
}

void Module::Operate()
{

}


void Module::save(ofstream& savefile)
{
	savefile << "MOD" << "\t" << id << "\tLabel\t" << value << "\t" << R1 << "\t" << R2 << "\t" << R3 << "\t" << R4 << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y << endl;
}

void Module::load(ifstream& loadfile)
{
}

Component* Module::createcopy()
{
	return nullptr;
}


 