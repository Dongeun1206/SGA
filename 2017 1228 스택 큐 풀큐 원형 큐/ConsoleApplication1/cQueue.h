#pragma once

class cNode;

class cQueue
{
public:
	cNode* m_pFront;
	cNode* m_pRear;

public:
	cQueue();
	~cQueue();

	void Enqueue(int n);
	void Enqueue(cNode* pNode);
	cNode* Dequeue();
	void Print();
	bool IsEmpty();
};

