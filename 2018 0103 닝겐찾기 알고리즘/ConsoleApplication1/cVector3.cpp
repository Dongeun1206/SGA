#include "stdafx.h"
#include "cVector3.h"


cVector3::cVector3()
{
}

cVector3::cVector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}


cVector3::~cVector3()
{
}

cVector3 cVector3::operator+(CONST cVector3& vec) const
{
	cVector3 v;
	
	v.x = x + vec.x;
	v.y = y + vec.y;
	v.z = z + vec.z;

	return v;
}

cVector3 cVector3::operator-(CONST cVector3& vec) const
{
	cVector3 v;

	v.x = x - vec.x;
	v.y = y - vec.y;
	v.z = z - vec.z;

	return v;
}

cVector3 cVector3::operator*(float f) const
{
	cVector3 v;

	v.x = x * f;
	v.y = y * f;
	v.z = z * f;

	return v;
}

bool cVector3::operator==(CONST cVector3& vec) const
{
	return (fabs(x - vec.x) < FLT_EPSILON && fabs(y - vec.y) < FLT_EPSILON && fabs(z - vec.z) < FLT_EPSILON) ;
}

bool cVector3::operator!=(CONST cVector3& vec) const
{
	return !(*this == vec);
}

float cVector3::Length()
{
	return sqrt(x*x + y*y + z*z);
}

float cVector3::LengthSq()
{
	return (x*x + y*y + z*z);
}

cVector3 cVector3::Normalize()
{
	cVector3 v;
	return v = { x / Length(), y / Length(), z / Length() };
}

float cVector3::Dot(cVector3 & v1, cVector3 & v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z + v2.z);
}

cVector3 cVector3::Cross(cVector3 & v1, cVector3 & v2)
{
	cVector3 p;
	p = { (v1.y * v2.z - v1.z * v2.y), (v1.z * v2.x - v1.x * v2.z),
		(v1.x * v2.y - v1.y * v2.x) };
	return p;
}
