#include "stdafx.h"
#include "cTown.h"


cTown::cTown()
{
	m_mapHuman.clear();
	m_mapTown.clear();
	m_vecHuman.clear();
}


cTown::~cTown()
{
}

vector<int> cTown::Human(string number)
{
	vector<int> vecHuman;
	string sz = "";

	for (int i = 0; i < number.length(); i++)	//��Ʈ�� ���� ��ŭ ���� ����
	{
		if (number[i] == ' ')	//������ ������ sz���� ��Ʈ������ ���Ϳ� �־��� sz���� ��Ʈ�� ���� else���� ���ڸ� ������ �尨.
		{
			vecHuman.push_back(atoi(sz.c_str()));
			sz = ""; //���Ϳ� ���� ������ ������� �ʱ�ȭ
		}
		else if (number[i] == '\n') //���� �����ٸ�
		{
			if (number[i - 1] != ' ') //���� 1�� ��츸 
				vecHuman.push_back(atoi(sz.c_str()));

			break;
		}
		else  // ���ڸ� ������ ��
		{
			sz += number[i];
		}
	}

	if (vecHuman.size() > 2)
	{
		vecHuman.erase(vecHuman.begin());  //ù��°
		vecHuman.erase(vecHuman.begin());  //�ι�°�� �������ν� �ڽŰ� �ڽ��� ������ ������� ����
	}

	return vecHuman;	//����� ������ ����� ���� �ߴٵ���� ���͸� ��ȯ�Ѵ�. 
}

void cTown::PushHuman(int num)
{
	if (m_mapHuman.find(num) == m_mapHuman.end())	//������ �Դٴ� �� �ߺ��� ���ٴ� ��.
	{
		m_mapHuman[num] = Human(m_mapTown[num]);	// ����ֱ�(�����ȣ, ����̰���Ű�� �����)
		m_vecHuman.push_back(num);
	}
}

void cTown::SetTown(FILE * fp)
{
	int count = 0;
	while (true)
	{
		if (feof(fp)) break;

		char szBuf[1024];
		fgets(szBuf, 1024, fp);		//���پ� �о�ͼ�

		m_mapTown[count] = szBuf;	//���������� ���پ� �־� �ش�.
		++count;
	}
}

void cTown::CountHuman()
{
	PushHuman(1);		//1���� ������ ��������� ó���� �ְ� ����.

	for (int i = 0; i < m_vecHuman.size(); i++)
	{
		vector<int> human = m_mapHuman[m_vecHuman[i]];	//����� ����Ű���ִ� ����� ���Ϳ� �־���.

		for (auto iter = human.begin(); iter < human.end(); iter++)		//�����̱� ������ �������� �˻�
		{
			PushHuman(*iter);		//����� �ִ� �� üũ�ϰ� �ֱ�
		}
	}
}