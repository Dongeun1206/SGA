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

	for (int i = 0; i < number.length(); i++)	//스트링 길이 만큼 포문 돌림
	{
		if (number[i] == ' ')	//공백을 만나면 sz안의 스트링값을 벡터에 넣어줌 sz안의 스트링 값은 else에서 숫자를 만나면 드감.
		{
			vecHuman.push_back(atoi(sz.c_str()));
			sz = ""; //벡터에 넣은 다음에 저장공간 초기화
		}
		else if (number[i] == '\n') //줄이 끝난다면
		{
			if (number[i - 1] != ' ') //마을 1의 경우만 
				vecHuman.push_back(atoi(sz.c_str()));

			break;
		}
		else  // 숫자를 만났을 때
		{
			sz += number[i];
		}
	}

	if (vecHuman.size() > 2)
	{
		vecHuman.erase(vecHuman.begin());  //첫번째
		vecHuman.erase(vecHuman.begin());  //두번째를 빼줌으로써 자신과 자신이 지목한 사람수를 빼줌
	}

	return vecHuman;	//사람이 지목한 사람만 남은 잘다듬어진 벡터를 반환한다. 
}

void cTown::PushHuman(int num)
{
	if (m_mapHuman.find(num) == m_mapHuman.end())	//끝까지 왔다는 건 중복이 없다는 뜻.
	{
		m_mapHuman[num] = Human(m_mapTown[num]);	// 사람넣기(사람번호, 사람이가리키는 사람들)
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
		fgets(szBuf, 1024, fp);		//한줄씩 읽어와서

		m_mapTown[count] = szBuf;	//마을정보에 한줄씩 넣어 준다.
		++count;
	}
}

void cTown::CountHuman()
{
	PushHuman(1);		//1번은 무조건 사람임으로 처음에 넣고 시작.

	for (int i = 0; i < m_vecHuman.size(); i++)
	{
		vector<int> human = m_mapHuman[m_vecHuman[i]];	//사람이 가리키고있는 사람을 벡터에 넣어줌.

		for (auto iter = human.begin(); iter < human.end(); iter++)		//벡터이기 때문에 포문으로 검사
		{
			PushHuman(*iter);		//사람이 있는 지 체크하고 넣기
		}
	}
}