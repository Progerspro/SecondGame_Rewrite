#pragma once
#include "GameOBJ.h"
class Charcter : public GameOBJ
{
public:
	Charcter();
	~Charcter();

	void LoadCharcter();
	void DrawCharcter();

	void HandleEvent();
	void Move();

};

