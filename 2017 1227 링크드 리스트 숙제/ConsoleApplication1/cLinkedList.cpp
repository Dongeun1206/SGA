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
	//��带 �ϳ� ����� ��
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
		temp = m_pHead;		//������ == ���͹��� �������� ����

		while (temp->GetNext() != NULL)		//������ ����κ� ����
		{
			temp = temp->GetNext();		//������ ++ �κ�
		}

		temp->SetNext(node);	//temp->GetNex() == NULL�϶� ��
	}
}

void cLinkedList::Delete(int n)
{
	cNode* temp = m_pHead; //���� ���
	cNode* preNode = NULL; //���� ���

	int count = 0; //�ݺ��� üũ�ϴ� ī��Ʈ

	while (temp->GetValue() != n) //iter�� value�� ������ �����
	{
		if (temp->GetNext() == NULL) // �˻��ϴ� ���� �������
		{
			return; //�Լ� ������
		}
		else
		{
			preNode = temp; // ��������� ���� ��尡 ���� ����� ������ ������
			temp = temp->GetNext(); //���� ���� ���� iter++
		}

		count++; //ī��Ʈ ����
	}

	if (count == 0) //�ݺ����� ���� ������
	{
		m_pHead = temp->GetNext(); // �� ���� ������
	}
	else
	{
		if (temp->GetNext() == NULL) // ���̸�
			preNode->SetNext(NULL); // ���� ��带 NULL�� ����
		else
			preNode->SetNext(temp->GetNext()); //���� �ƴϸ� ���� ������� ����� ���� ��带 ���� ���� ����
	}

	delete temp; //���� ��带 �����.
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
		
		iter = m_pHead;		//ó�� ������

		m_pHead = iter->GetNext();	//��带 �����ڸ��� �Ѱ��ִ� ����

		iter->SetNext(temp);		//���� ����ڸ��� �ִ� �ؽ�Ʈ�� �ΰ� ����.	

		temp = iter;		//�������� 
	}
	m_pHead->SetNext(temp);
}

void cLinkedList::ReadData()
{

}
