#pragma once
#include "Shape.h"
class ShapeD :
	public shape
{
public:
	ShapeD() ;
	~ShapeD();
private:
	virtual void setOrigin()override;


};

