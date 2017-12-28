#include "stdafx.h"
#include "cStack.h"
#include "cNode.h"

cStack::cStack()
	:m_pTop(NULL)
{
}


cStack::~cStack()
{
}

void cStack::Push(int n)
{
	cNode* prevTop;
	cNode* newTop;
	
	if (m_pTop == NULL)
	{
		m_pTop = new cNode(n);
	}
	else
	{
		prevTop = m_pTop;
		newTop = new cNode(n);
		newTop->SetNext(prevTop);
		m_pTop = newTop;
	}
}

cNode * cStack::Pop()
{
	cNode* node = NULL;
	if (m_pTop)
	{
		node = m_pTop;
		m_pTop = m_pTop->GetNext();
	}

	return node;
}

void cStack::Print()
{
	if (m_pTop == NULL) return;

	m_pTop->Print();
}
