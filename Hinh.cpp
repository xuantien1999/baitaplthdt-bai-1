#include "stdafx.h"
#include "Hinh.h"


Hinh::Hinh()
{
}


Hinh::~Hinh()
{
}


void Hinh::draw(CClientDC *pdc)
{
	// TODO: Add your implementation code here.
}
Hinh::Hinh(int mx1 )
{
	x1 = mx1;
	
}
void Hinh::thietlap(int mx1 )
{
	x1 = mx1;
	}

float Hinh::dientichhv()
{
	// TODO: Add your implementation code here.
	float x1=200, s=0;
s=x1*x1;
return s;
}
float Hinh::chuvihv()
{float x1=200,p;
p=4*x1;
	// TODO: Add your implementation code here.
	 return p;
}