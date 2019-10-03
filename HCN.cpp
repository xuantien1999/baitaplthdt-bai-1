#include "stdafx.h"
#include "HCN.h"
#include<math.h>

HCN::HCN()
{
}
HCN::HCN(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
}
HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::draw(CClientDC *pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
	CString strs,strc,s,c;
	s=("dien tich la: ");
	strs.Format(_T("%f"), dientichhv());
	c=("chu vi la:");
	strc.Format(_T("%f"), chuvihv());
	pdc->TextOutW(700, 50, s);
	pdc->TextOutW(900, 50, strs);
	pdc->TextOutW(700, 80, c);
	pdc->TextOutW(900, 80, strc);
}
CPoint HCN::getA()
{
	return CPoint(x1, y1);
}
CPoint HCN::getC()
{
	return CPoint(x2, y2);
}

HCN::~HCN()
{
}

float HCN::dientich()
{
	// TODO: Add your implementation code here.
	float kq = 0;
	kq = (x2 - x1)*(y2 - y1);
	return kq;
}
float HCN::chuvi()
{
	// TODO: Add your implementation code here.
	float kq = 0;
	kq = ((x2 - x1)+(y2 - y1))/2;
	return kq;
}
