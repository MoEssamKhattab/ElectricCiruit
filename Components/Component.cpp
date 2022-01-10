#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

GraphicsInfo* Component::getGraphicsInfo()
{
	return m_pGfxInfo;
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
}

bool Component::getSelected()
{
	return selected;
}

void Component::setSelected(bool sel)
{
	selected = sel;
}


void Component::SetValue(int v)
{
	value = v;
}

int Component::GetValue()
{
	return value;
}

int Component::Ccount = 0;

Component::~Component()
{}

