#pragma once
#include "Shape.h"
class ShapeC :
	public shape
{
public:
	ShapeC();
	~ShapeC();
private:
	virtual void setOrigin()override;


};

