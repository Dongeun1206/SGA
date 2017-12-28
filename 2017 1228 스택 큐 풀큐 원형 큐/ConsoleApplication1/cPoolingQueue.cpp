#include "stdafx.h"
#include "cPoolingQueue.h"
#include "cQueue.h"
#include "cNode.h"

cPoolingQueue::cPoolingQueue()
{
	m_pQueue = new cQueue;
	m_pMemoryPool = new cQueue;
}


cPoolingQueue::~cPoolingQueue()
{
	delete m_pQueue;
	m_pQueue = NULL;
	delete m_pMemoryPool;
	m_pMemoryPool = NULL;
}

void cPoolingQueue::Enqueue(int n)
{
	if (m_pMemoryPool->IsEmpty())
	{
		m_pQueue->Enqueue(n);
	}
	else
	{
		cNode* temp = m_pMemoryPool->Dequeue();

		if (temp != NULL)	
		{
			temp->SetValue(n);	
			m_pQueue->Enqueue(temp);
		}
		else
			m_pQueue->Enqueue(n);
	}
	//�޸�Ǯ�� ���ٸ� �� �������
	//�޸�Ǯ�� ť�� �� ���� �ִٸ� �޸�Ǯ���� �����ͼ� ����.
}

cNode * cPoolingQueue::Dequeue()
{
	cNode* temp = m_pQueue->Dequeue();
	m_pMemoryPool->Enqueue(temp);
	return temp;
}

void cPoolingQueue::Print()
{
	cNode* iter = m_pQueue->m_pFront;
	//����� ��� ���� ���ÿ����÷ο� �߻�, ���Ϲ� �������� ����
	while (iter != NULL)
	{
		cout << iter->GetValue() << endl;
		iter = iter->GetNext();
	}
}

bool cPoolingQueue::IsEmpty()
{
	return m_pMemoryPool->IsEmpty();
}
