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
		cout << "풀" << endl;
	}
	else
	{
		m_aData[m_nRear] = n;
		m_nRear++;
		m_nRear = (m_nRear) % 5;	//리어 범위 제한
	}
}

int* cCircularQueue::Dequeue()
{
	int* result = new int;		//초기화

	if (!IsEmpty())
	{
		*result = m_aData[m_nFront];
		m_nFront++;

		m_nFront = m_nFront % 5;	//프론트 범위 제한

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
		i = i % 5;					// 프론트 자리를 옮겼음으로 프론트 부터 리어까지만 출력
									//i 값 제한.
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
