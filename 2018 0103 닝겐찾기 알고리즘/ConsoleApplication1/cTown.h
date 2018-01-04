#pragma once
class cTown
{
private:
	map<int, string>		m_mapTown;	// �������� ��
	map<int, vector<int>>	m_mapHuman; // ������� ���� ��
	vector<int> m_vecHuman;				// ��� ��ȣ ����(����� ���� �� �ο����� �� �� ����)
	
public:
	cTown();
	~cTown();

	vector<int> Human(string number);
	void PushHuman(int num);
	void SetTown(FILE* fp);
	void CountHuman();

	int GetHumanCnt() { return m_mapHuman.size(); }
};