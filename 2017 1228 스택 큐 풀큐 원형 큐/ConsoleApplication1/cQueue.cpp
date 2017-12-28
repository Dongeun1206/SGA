#include "stdafx.h"
#include "cQueue.h"
#include "cNode.h"

cQueue::cQueue()
{
}


cQueue::~cQueue()
{
	while (m_pFront != NULL)
	{
		cNode* temp = m_pFront;
		m_pFront = m_pFront->GetNext();

		delete temp;
		temp = NULL;
	}
}

void cQueue::Enqueue(int n)
{
	if (m_pFront == NULL)
	{
		m_pFront = new cNode(n);
		m_pRear = m_pFront;
	}
	else
	{
		m_pRear->SetNext(new cNode(n));
		m_pRear = m_pRear->GetNext();
	}
}

void cQueue::Enqueue(cNode * pNode)
{
	if (m_pFront == NULL)
	{
		m_pFront = pNode;
		m_pRear = m_pFront;
	}
	else
	{
		m_pRear->SetNext(pNode);
		m_pRear = pNode;
	}
}

cNode * cQueue::Dequeue()
{
	if (m_pFront == NULL)
		return NULL;

	cNode* node = m_pFront;
	m_pFront = m_pFront->GetNext();
	node->SetNext(NULL);

	return node;
}

void cQueue::Print()
{
	if (m_pFront == NULL) return;

	cNode* iter = m_pFront;
	//재귀적 방법 사용시 스택오버플로우 발생, 와일문 형식으로 변경
	while (iter != NULL)
	{
		cout << iter->GetValue() << endl;
		iter = iter->GetNext();
	}
}

bool cQueue::IsEmpty()
{
	if (m_pFront == NULL)
		return true;
	else
		return false;
}
