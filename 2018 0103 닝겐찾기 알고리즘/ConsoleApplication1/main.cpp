// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cVector3.h"
#include <vector>
#include <math.h>
#include "cTown.h"

void main()
{
	//인간 찾기
	cTown* town = new cTown;

	FILE* fp = NULL;
	fopen_s(&fp, "마을2.txt", "r");
	
	town->SetTown(fp);
	town->CountHuman();
	cout << "사람 수 : " << town->GetHumanCnt() << " " << endl;

	SAFE_DELETE(town);

	system("pause");
	//한 줄 씩 데이터를 받아와서 공백 기준으로 벡터에 나눠 담음.

	// 나눠 담은 데이터 1번쨰 2번쨰 삭제 하여 사람이 가르키는 사람만 남도록.

	// 반복문 돌면서 가르키는 사람이 또 가르키는 사람으로 넘어가도록.
}

