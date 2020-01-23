#pragma once
#include "Shape.h"
class ShapeF :
	public shape
{
public:
	ShapeF();
	~ShapeF();
private:
	virtual void setOrigin()override;



};

