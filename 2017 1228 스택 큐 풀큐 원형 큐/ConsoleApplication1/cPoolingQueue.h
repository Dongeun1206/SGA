#pragma once

class cNode;
class cQueue;

class cPoolingQueue
{
private:
	cQueue*		m_pQueue;
	cQueue*		m_pMemoryPool;

public:
	cPoolingQueue();
	~cPoolingQueue();

	void Enqueue(int n);
	cNode* Dequeue();
	void Print();
	bool IsEmpty();
};

