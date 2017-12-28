#include "stdafx.h"
#include "cCircularQueue.h"


cCircularQueue::cCircularQueue()
{
	m_nRear = 0;
	m_nFront = 0;
}


cCircularQueue::~cCircularQueue()
{
}

void cCircularQueue::Enqueue(int n)
{
	if (IsFull())
	{
		cout << "Ǯ" << endl;
	}
	else
	{
		m_aData[m_nRear] = n;
		m_nRear++;
		m_nRear = (m_nRear) % 5;	//���� ���� ����
	}
}

int* cCircularQueue::Dequeue()
{
	int* result = new int;		//�ʱ�ȭ

	if (!IsEmpty())
	{
		*result = m_aData[m_nFront];
		m_nFront++;

		m_nFront = m_nFront % 5;	//����Ʈ ���� ����

		return result;
	}
	else
		return NULL;
}

void cCircularQueue::Print()
{
	if (m_aData[m_nRear] == NULL) return;

	for (int i = m_nFront; i < m_nRear; i++)
	{
		i = i % 5;					// ����Ʈ �ڸ��� �Ű������� ����Ʈ ���� ��������� ���
									//i �� ����.
		cout << m_aData[i] << endl;
	}
}

bool cCircularQueue::IsFull()
{
	return m_nFront == (m_nRear + 1) % 5;
}

bool cCircularQueue::IsEmpty()
{
	if (m_nFront == m_nRear)
		return true;
	else
		return false;
}
