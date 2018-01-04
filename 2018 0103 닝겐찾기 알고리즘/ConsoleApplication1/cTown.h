#pragma once
class cTown
{
private:
	map<int, string>		m_mapTown;	// 마을정보 맵
	map<int, vector<int>>	m_mapHuman; // 사람정보 담을 맵
	vector<int> m_vecHuman;				// 사람 번호 벡터(사이즈를 통해 총 인원수를 알 수 있음)
	
public:
	cTown();
	~cTown();

	vector<int> Human(string number);
	void PushHuman(int num);
	void SetTown(FILE* fp);
	void CountHuman();

	int GetHumanCnt() { return m_mapHuman.size(); }
};