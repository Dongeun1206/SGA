// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cLinkedList.h"

void main()
{
	cLinkedList link;

	string szData;
	ifstream data;
	data.open("data.txt", ios_base::in);

	while (data >> szData)		//한줄 씩 받아오는
	{
		if (szData.substr(0, 1) == "i")		//인설트
		{
			int value = atoi(szData.substr(2).c_str());
			link.Insert(value);
		}
		else if (szData.substr(0, 1) == "p")		//프린트
		{
			link.Print();
			cout << "===============영역구분=================" << endl;
			cout << "=======================================" << endl;
		}
		else if (szData.substr(0, 1) == "d")		//딜리트
		{
			int value = atoi(szData.substr(2).c_str());
			link.Delete(value);
		}
		else if (szData.substr(0, 1) == "r")		//리버스
		{
			link.Reverse();
		}
	}
}

/*
data.txt
i:3		Insert(3)
d:2		Delete(2)
p		Print()
r		Reverse()
*/