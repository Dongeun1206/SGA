#include "stdafx.h"
#include "cLinkedList.h"
#include "cNode.h"

cLinkedList::cLinkedList()
{
	
}


cLinkedList::~cLinkedList()
{
}

void cLinkedList::Insert(int n)
{
	//노드를 하나 만드는 것
	cNode* node = new cNode;
	node->SetNext(NULL);
	node->SetValue(n);

	if (m_pHead == NULL)
	{
		m_pHead = node;
	}
	else
	{
		cNode* temp = new cNode;
		temp = m_pHead;		//시작점 == 이터문의 비긴과같은 역할

		while (temp->GetNext() != NULL)		//이터의 엔드부분 역할
		{
			temp = temp->GetNext();		//이터의 ++ 부분
		}

		temp->SetNext(node);	//temp->GetNex() == NULL일때 들어감
	}
}

void cLinkedList::Delete(int n)
{
	cNode* temp = m_pHead; //시작 노드
	cNode* preNode = NULL; //이전 노드

	int count = 0; //반복문 체크하는 카운트

	while (temp->GetValue() != n) //iter가 value와 같으면 멈춘다
	{
		if (temp->GetNext() == NULL) // 검색하는 값이 없을경우
		{
			return; //함수 끝낸다
		}
		else
		{
			preNode = temp; // 지우기전에 이전 노드가 현재 노드의 정보를 가진다
			temp = temp->GetNext(); //다음 노드로 연결 iter++
		}

		count++; //카운트 증가
	}

	if (count == 0) //반복문이 돌지 않으면
	{
		m_pHead = temp->GetNext(); // 맨 앞을 지울경우
	}
	else
	{
		if (temp->GetNext() == NULL) // 끝이면
			preNode->SetNext(NULL); // 이전 노드를 NULL로 연결
		else
			preNode->SetNext(temp->GetNext()); //끝이 아니면 원래 지우려는 노드의 다음 노드를 이전 노드와 연결
	}

	delete temp; //현재 노드를 지운다.
}

void cLinkedList::Print()
{
	cNode* temp = m_pHead;

	while (temp->GetNext() != NULL)
	{
		cout << temp->GetValue() << endl;
		temp = temp->GetNext();
	}

	cout << temp->GetValue() << endl;
}

void cLinkedList::Reverse()
{
	cNode* iter = NULL;
	cNode* temp = NULL;
	
	while (m_pHead->GetNext() != NULL)
	{
		
		iter = m_pHead;		//처음 시작점

		m_pHead = iter->GetNext();	//헤드를 다음자리로 넘겨주는 역할

		iter->SetNext(temp);		//원래 헤드자리에 있던 넥스트에 널값 넣음.	

		temp = iter;		//다음으로 
	}
	m_pHead->SetNext(temp);
}

void cLinkedList::ReadData()
{

}
