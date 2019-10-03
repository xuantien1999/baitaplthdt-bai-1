#pragma once
class Hinh
{
public:int x1;
	CPoint point1, point2;
	
	Hinh(int x1);
	void thietlap(int x1);
	Hinh();
	~Hinh();
	virtual void draw(CClientDC *pdc);
	virtual float dientichhv();
	virtual float chuvihv();
};

