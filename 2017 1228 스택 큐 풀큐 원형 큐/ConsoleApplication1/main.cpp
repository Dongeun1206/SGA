// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cLinkedList.h"
#include "cStack.h"
#include "cQueue.h"
#include "cCircularQueue.h"
#include "cNode.h"
#include "cPoolingQueue.h"

void LinkedListTest();

void main()
{
	//LinkedListTest();
	
	////====================스택 부분
	cStack* stack = new cStack;

	
	stack->Push(1);
	stack->Push(3);
	stack->Push(4);
	stack->Push(5);
	delete(stack->Pop());

	stack->Print();
	cout << "스택 부분 ================" << endl;
	//
	////============================

	//============================큐
	/*cQueue* queue = new cQueue;
	cNode  sk(5);
	queue->Enqueue(3);
	queue->Enqueue(4);
	queue->Enqueue(1);
	queue->Enqueue(&sk);
	delete(queue->Dequeue());
	queue->Print();*/
	//=============================

	//============================원형 
	cCircularQueue* queue2 = new cCircularQueue;

	queue2->Enqueue(3);
	queue2->Enqueue(4);
	queue2->Enqueue(1);
	queue2->Enqueue(6);

	int* temp = queue2->Dequeue();
	delete temp;
	temp = NULL;

	queue2->Print();
	//=============================
	//============================메모리 풀
	/*cPoolingQueue* queue3 = new cPoolingQueue;

	queue3->Enqueue(3);
	queue3->Enqueue(4);
	queue3->Enqueue(1);
	queue3->Enqueue(6);
	queue3->Enqueue(3);
	queue3->Enqueue(4);
	queue3->Enqueue(1);
	queue3->Enqueue(6);
	queue3->Dequeue();

	queue3->Print();*/
	//=============================

	
	DWORD dwStart, dwEnd, dwQueue, dwPQueue;

	dwStart = GetTickCount();
	//++++++++++풀큐+++++++++++++++
	cPoolingQueue* queue3 = new cPoolingQueue;
	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < 2000; i++)
		{
			queue3->Enqueue(i);
		}
		
		int j = 0;
		while (j < 2000)
		{
			queue3->Dequeue();
			j++;
		}
	}

	dwEnd = GetTickCount();

	dwPQueue = dwEnd - dwStart;

	cout << "메모리 풀 큐 결과값 : " << dwPQueue << endl;
	//queue3->Print();
	//++++++++++++++++++++++++++++
	dwStart = GetTickCount();
	cQueue* queue = new cQueue;
	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < 2000; i++)
		{
			queue->Enqueue(i);
		}

		int j = 0;
		while (j < 2000)
		{
			cNode* temp = queue->Dequeue();
			delete temp;
			temp = NULL;
			j++;
		}
	}
	
	//queue->Print();

	dwEnd = GetTickCount();

	dwQueue = dwEnd - dwStart;

	cout << " 큐 결과값 : " << dwQueue << endl;
	/*
	큐 알고리즘 작성

	링크드 리스크 큐와 메모리풀링(링크드 리스트) 큐 속도 차이 배율로 출력

	*/

	delete queue;
	queue = NULL;
	delete queue3;
	queue3 = NULL;

	system("pause");
}

void LinkedListTest()
{
	cLinkedList* pList = new cLinkedList;

	FILE* fp = NULL;
	fopen_s(&fp, "data.txt", "r");

	while (true)
	{
		if (feof(fp)) break;		// 파일 커서가 마지막 도달하면 종료

		char szBuf[1024];
		fgets(szBuf, 1024, fp);		// 한줄씩 읽는다. fgetc : 한자씩 읽는다.

		if (szBuf[0] == 'i')
		{
			pList->Insert(atoi(&szBuf[2]));
		}
		else if (szBuf[0] == 'd')
		{
			pList->Delete(atoi(&szBuf[2]));
		}
		else if (szBuf[0] == 'p')
		{
			pList->Print();
		}
		else if (szBuf[0] == 'r')
		{
			pList->Reverse();
		}
	}

	fclose(fp);

	delete pList;
}