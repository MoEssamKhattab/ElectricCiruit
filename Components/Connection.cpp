#include "Connection.h"

Connection::Connection(GraphicsInfo *r_GfxInfo1, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo1;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
}
GraphicsInfo* Connection::getConctsInfo()
{
	return pGfxInfo;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, selected);
}
bool Connection::getSelected()
{
	return selected;
}

void Connection::setSelected(bool sel)
{
	selected = sel;
}
void Connection::save(ofstream& savefile)
{
}
void Connection::load(ifstream& loadfile)
{
}
//string Connection::getlabelc()
//{
//	return m_labelc;
//}
//void Connection::setlabelc(string sel)
//{
//	m_labelc = sel;
//}


