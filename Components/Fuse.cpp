#include "Fuse.h"

Fuse::Fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	Ccount++;
}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass fuse drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, selected); //update to draw fuse

}
void Fuse::save(ofstream& savefile)
{
}
void Fuse::load(ifstream& loadfile)
{
}
//void Fuse::setlabel(string label)
//{
//	m_Label = label;
//}
Component* Fuse::createcopy()
{
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	Component* Copycomp = new Fuse(pGInfo);
	return Copycomp;
}
//string Fuse::getlabel()
//{
//	return m_Label;
//}

void Fuse::Operate()
{

}