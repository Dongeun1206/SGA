#pragma once
class cVector3
{
public:
	float x, y, z;

public:
	cVector3();
	cVector3(float _x, float _y, float _z);
	~cVector3();
	
	cVector3 operator + (CONST cVector3& vec) const;
	cVector3 operator - (CONST cVector3& vec) const;
	cVector3 operator * (float f) const;		//��Į�� ��

	bool operator == (CONST cVector3& vec) const;
	bool operator != (CONST cVector3& vec) const;

	/* ������ �������̵� ����
	+ 
	-
	* (��Į�� ��)
	==
	!=

	ex)
	cVector3 v1, v2 , v3;
	v3 = v1 + v2;
	if (v1 == v2) cout << "����";
	*/

	// ������ ����(ũ��)
	float Length();
	// ������ ���� ����
	float LengthSq();
	// ����ȭ �Լ�(��ֶ�����)
	cVector3 Normalize();
	// ���� (�� ���δ�Ʈ)
	static float Dot(cVector3& v1, cVector3& v2);
	// ���� (ũ�ν� ���δ�Ʈ)
	static cVector3 Cross(cVector3& v1, cVector3& v2);

	// ��å 32 ~ 60 ���� �б� (��Ʈ����)
};

